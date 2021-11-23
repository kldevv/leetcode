/*
Number: 378
Topic: Design Phone Directory
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/design-phone-directory/

Design a Snake game that is played on a device with screen size height x width. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.

You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.

When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving (i.e. a snake of length 4 cannot run into itself).

Implement the SnakeGame class:
* SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
* int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.

Constraints:
* 1 <= width, height <= 104
* 1 <= food.length <= 50
* food[i].length == 2
* 0 <= ri < height
* 0 <= ci < width
* direction.length == 1
* direction is 'U', 'D', 'L', or 'R'.
* At most 104 calls will be made to move.
*/

class SnakeGame {
private:
    vector<vector<int>> food;
    deque<pair<int, int>> body;
    set<pair<int, int>> occupied;
    int foodIdx;
    int m, n;

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->m = height;
        this->n = width;
        this->food = food;
        this->foodIdx = 0;
        this->body.emplace_back(0, 0);
        this->occupied.insert(make_pair(0, 0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int i = body.front().first;
        int j = body.front().second;
        occupied.erase(body.back());

        switch (direction[0]) {
            case 'U':
                i -= 1;
                break;
            case 'D':
                i += 1;
                break;
            case 'R':
                j += 1;
                break;
            case 'L':
                j -= 1;
                break;
            default: break;
        }
        pair<int, int> newHead = make_pair(i, j);

        if (i < 0 || j < 0 || i >= m || j >= n || (occupied.count(newHead)))
            return -1;

        body.emplace_front(i, j);
        occupied.insert(newHead);

        if (foodIdx < food.size() && i == food[foodIdx][0] && j == food[foodIdx][1]) {
            foodIdx += 1;
            occupied.insert(body.back());
        }
        else {
            body.pop_back();
        }
        return body.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
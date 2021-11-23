/*
Number: 251
Topic: Flatten 2D Vector
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/flatten-2d-vector/

Design an iterator to flatten a 2D vector. It should support the next and hasNext operations.

Implement the Vector2D class:
* Vector2D(int[][] vec) initializes the object with the 2D vector vec.
* next() returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to next are valid.
* hasNext() returns true if there are still some elements in the vector, and false otherwise.

Constraints:
* 0 <= vec.length <= 200
* 0 <= vec[i].length <= 500
* -500 <= vec[i][j] <= 500
* At most 105 calls will be made to next and hasNext.
*/


class Vector2D {
private:
    vector<vector<int>>::iterator vecItr;
    vector<vector<int>>::iterator vecEnd;
    int i;
public:
    Vector2D(vector<vector<int>>& vec) {
        vecItr = vec.begin();
        vecEnd = vec.end();
        i = 0;
    }
    
    int next() {
        hasNext();
        return (*vecItr)[i++];
    }
    
    bool hasNext() {
        while (vecItr != vecEnd && i == (*vecItr).size()) {
            vecItr += 1;
            i = 0;
        }
        return vecItr != vecEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
/*
Number: 355
Topic: Design Twitter
Date: 2021/7/13
Rate: Medium
https://leetcode.com/problems/design-twitter/

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

* Twitter() Initializes your twitter object.
* void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
* List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
* void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
* void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

Constraints:
* 1 <= capacity <= 3000
* 0 <= key <= 104
* 0 <= value <= 105
* At most 2 * 105 calls will be made to get and put.
*/

static int timer = 0;

struct Tweet {
    int context;
    int timeStamp;
    Tweet* nextTweet;
    Tweet(int context) : context(context), timeStamp(timer++), nextTweet(nullptr) {};

};

class User {
private:
    int userId;
    unordered_set<User*> followedId;
    Tweet* tweetHead;

public:
    User(int id): userId(id), tweetHead(nullptr) {
        this->followedId.insert(this);
    }

    void addTweet(int context) {
        Tweet* newTweet = new Tweet(context);
        newTweet->nextTweet = tweetHead;
        this->tweetHead = newTweet;
    }

    void addFollowed(User* user) {
        followedId.insert(user);
    }
    void unfollowed(User* user) {
        followedId.erase(user);
    }

    unordered_set<User*> getFollowedUser() {
        return this->followedId;
    }

    Tweet* getTweetHead() {
        return this->tweetHead;
    }
};

class Twitter {
private:
    unordered_map<int, User*> umap;

public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (!umap.count(userId)) {
            umap[userId] = new User(userId);
        }
        umap[userId]->addTweet(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> out;
        if (!umap.count(userId))
            return out;

        priority_queue<pair<int, int>> rankTemp;

        for (User* id : umap[userId]->getFollowedUser()) {
            Tweet* tweetNode = id->getTweetHead();
            while (tweetNode) {
                rankTemp.push(make_pair(tweetNode->timeStamp, tweetNode->context));
                tweetNode = tweetNode->nextTweet;
            }
        }

        while (out.size() < 10 && !rankTemp.empty()) {
            out.push_back(rankTemp.top().second);
            rankTemp.pop();
        }
        return out;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (!umap.count(followerId)) {
            umap[followerId] = new User(followerId);
        }
        if (!umap.count(followeeId)) {
            umap[followeeId] = new User(followeeId);
        }
        umap[followerId]->addFollowed(umap[followeeId]);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (!umap.count(followerId) || !umap.count(followeeId))
            return;
        if (followerId != followeeId)
            umap[followerId]->unfollowed(umap[followeeId]);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
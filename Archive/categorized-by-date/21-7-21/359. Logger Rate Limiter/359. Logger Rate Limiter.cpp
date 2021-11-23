/*
Number: 359
Topic: Logger Rate Limiter
Date: 2021/7/21
Rate: Easy
https://leetcode.com/problems/logger-rate-limiter/

Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:
* Logger() Initializes the logger object.
* bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.

Constraints:
* 0 <= timestamp <= 109
* Every timestamp will be passed in non-decreasing order (chronological order).
* 1 <= message.length <= 30
* At most 104 calls will be made to shouldPrintMessage.

*/

class Logger {
private:
    unordered_map<string, int> nextTime;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (!nextTime.count(message) || nextTime[message] <= timestamp) {
            nextTime[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
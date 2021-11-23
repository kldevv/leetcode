/*
Number: 1628
Topic: Design an Expression Tree With Evaluate Function
Date: 2021/9/29
Rate: Medium
https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/

Given the postfix tokens of an arithmetic expression, build and return the binary expression tree that represents this expression.

Postfix notation is a notation for writing arithmetic expressions in which the operands (numbers) appear before their operators. For example, the postfix tokens of the expression 4*(5-(7+2)) are represented in the array postfix = ["4","5","7","2","+","-","*"].

The class Node is an interface you should use to implement the binary expression tree. The returned tree will be tested using the evaluate function, which is supposed to evaluate the tree's value. You should not remove the Node class; however, you can modify it as you wish, and you can define other classes to implement it if needed.

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with two children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

It's guaranteed that no subtree will yield a value that exceeds 109 in absolute value, and all the operations are valid (i.e., no division by zero).

    * Follow up: Could you design the expression tree such that it is more modular? For example, is your design able to support additional operators without making changes to your existing evaluate implementation?

Constraints:
    * 1 <= s.length < 100
    * s.length is odd.
    * s consists of numbers and the characters '+', '-', '*', and '/'.
    * If s[i] is a number, its integer representation is no more than 105.
    * It is guaranteed that s is a valid expression.
    * The absolute value of the result and intermediate values will not exceed 109.
    * It is guaranteed that no expression will include division by zero.
*/

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
};

class NumNode : public Node {
private:
    int _value;
public:
    NumNode(int num) : _value(num) {}
    int evaluate() const {
        return _value;
    };
};

class OperatorNode : public Node {
protected:
    Node* _left;
    Node* _right;
public:
    OperatorNode(Node* left, Node* right) : _left(left), _right(right) {}
    ~OperatorNode() {
        delete _left;
        delete _right;
    }
};

class AddOperatorNode : public OperatorNode {
public:
    AddOperatorNode(Node* left, Node* right) : OperatorNode(left, right) {}
    int evaluate() const override {
        return _left->evaluate() + _right->evaluate();
    };
};

class SubtractOperatorNode : public OperatorNode {
public:
    SubtractOperatorNode(Node* left, Node* right) : OperatorNode(left, right) {}
    int evaluate() const override {
        return _left->evaluate() - _right->evaluate();
    };
};

class MultiplyOperatorNode : public OperatorNode {
public:
    MultiplyOperatorNode(Node* left, Node* right) : OperatorNode(left, right) {}
    int evaluate() const override {
        return _left->evaluate() * _right->evaluate();
    };
};

class DivideOperatorNode : public OperatorNode {
public:
    DivideOperatorNode(Node* left, Node* right) : OperatorNode(left, right) {}
    int evaluate() const override {
        return _left->evaluate() / _right->evaluate();
    };
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
private:
    int getNum(string& s) {
        int result = 0;
        for (char& c : s) {
            result *= 10;
            result += c - '0';
        }
        return result;
    }

    Node* getNumNode(string& s) {
        return new NumNode(getNum(s));
    }

    Node* getOperatorNode(string& ops, Node* left, Node* right) {
        switch (ops[0]) {
            case '+':
                return new AddOperatorNode(left, right);
            case '-':
                return new SubtractOperatorNode(left, right);
            case '/':
                return new DivideOperatorNode(left, right);
            case '*':
                return new MultiplyOperatorNode(left, right);
            default:
                return nullptr;
        }
    }
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> nodes;
        for (string& s : postfix) {
            if (isdigit(s[0])) {
                nodes.push(getNumNode(s));
            } else {
                Node* right = nodes.top(); nodes.pop();
                Node* left = nodes.top(); nodes.pop();
                nodes.push(getOperatorNode(s, left, right));
            }
        }
        return nodes.top();
    }
}; 

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
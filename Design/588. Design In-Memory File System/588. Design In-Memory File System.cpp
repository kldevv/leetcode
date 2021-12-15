/*
Number: 588
Topic: Design In-Memory File System
Date: 2021/12/2
Rate: Hard
https://leetcode.com/problems/design-in-memory-file-system/

Design a data structure that simulates an in-memory file system.

Implement the FileSystem class:

    * FileSystem() Initializes the object of the system.

    * List<String> ls(String path)
        * If path is a file path, returns a list that only contains this file's name.
        * If path is a directory path, returns the list of file and directory names in this directory.
    The answer should in lexicographic order.

    * void mkdir(String path) Makes a new directory according to the given path. The given directory path does not exist. If the middle directories in the path do not exist, you should create them as well.

    * void addContentToFile(String filePath, String content)
        * If filePath does not exist, creates that file containing given content.
        * If filePath already exists, appends the given content to original content.

    * String readContentFromFile(String filePath) Returns the content in the file at filePath.

Constraints:
    * 1 <= path.length, filePath.length <= 100
    * path and filePath are absolute paths which begin with '/' and do not end with '/' except that the path is just "/".
    * You can assume that all directory names and file names only contain lowercase letters, and the same names will not exist in the same directory.
    * You can assume that all operations will be passed valid parameters, and users will not attempt to retrieve file content or list a directory or file that does not exist.
    * 1 <= content.length <= 50
    * At most 300 calls will be made to ls, mkdir, addContentToFile, and readContentFromFile.
*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
   public:
    bool isFile;
    string content;
    string name;
    unordered_map<string, Node*> children;
    Node(string name, bool isFile) {
        this->name = name;
        this->isFile = isFile;
        content = "";
    }

    void addContent(string content) {
        this->content += content;
    }
};

class FileSystem {
   private:
    Node* root;

    vector<string> breakPath(string path) {
        int start = 1;
        int end = 1;
        path += "/";
        vector<string> result;
        for (; end < path.size(); end++) {
            if (path[end] == '/') {
                result.push_back(path.substr(start, end - start));
                start = end + 1;
            }
        }
        return result;
    }

   public:
    FileSystem() {
        root = new Node("root", false);
    }

    vector<string> ls(string path) {
        /*
        nodes = breakPath(path)
        for nodeName in nodeNames:
            iter = iter->children[nodeName]
        if iter is a file:
            return fileName
        else:
            return list(Node)
        */
        vector<string> paths = breakPath(path);
        Node* iter = root;
        if (path != "/") {
            for (string nodeName : paths) {
                if (iter->children.count(nodeName) == 0)
                    iter->children[nodeName] = new Node(nodeName, false);
                iter = iter->children[nodeName];
            }
            // is file
            if (iter->isFile)
                return {iter->name};
        }

        // is folder
        vector<string> results;
        for (auto pair : iter->children) {
            results.push_back(pair.first);
        }
        sort(results.begin(), results.end());
        return results;
    }

    void mkdir(string path) {
        /*
        nodes = breakPath(path)
        for nodeName in nodeNames:
            iter = iter->children[nodeName]
        */
        vector<string> paths = breakPath(path);
        Node* iter = root;

        for (string nodeName : paths) {
            if (iter->children.count(nodeName) == 0)
                iter->children[nodeName] = new Node(nodeName, false);
            iter = iter->children[nodeName];
        }
    }

    void addContentToFile(string filePath, string content) {
        /*
        nodes = breakPath(path)
        for nodeName in nodeNames[:-1]:
            iter = iter->children[nodeName]
        iter = iter->children[fileName]
        iter->addContent(content)
        */
        vector<string> paths = breakPath(filePath);
        Node* iter = root;

        string fileName = paths.back();
        paths.pop_back();
        // move to folder
        for (string nodeName : paths) {
            if (iter->children.count(nodeName) == 0)
                iter->children[nodeName] = new Node(nodeName, false);
            iter = iter->children[nodeName];
        }
        // creat file
        if (iter->children.count(fileName) == 0)
            iter->children[fileName] = new Node(fileName, true);
        // content
        iter->children[fileName]->content += content;
    }

    string readContentFromFile(string filePath) {
        /*
        nodes = breakPath(path)
        for nodeName in nodeNames[:-1]:
            iter = iter->children[nodeName]
        iter = children[fileName]
        iter->readContent()
        */
        vector<string> paths = breakPath(filePath);
        Node* iter = root;

        string fileName = paths.back();
        paths.pop_back();
        // move to folder
        for (string nodeName : paths) {
            if (iter->children.count(nodeName) == 0)
                iter->children[nodeName] = new Node(nodeName, false);
            iter = iter->children[nodeName];
        }
        // content
        return iter->children[fileName]->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
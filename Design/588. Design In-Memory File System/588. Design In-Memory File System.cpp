/*
Number: 588
Topic: Design In-Memory File System
Date: 2021/9/25
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

class FileSystem {
private:
    struct Node {
        bool hasFile = false;
        string content = "";
        unordered_map<string, Node*> subDirectory;
    };
    Node* root;
public:
    FileSystem() {
        this->root = new Node();
    }
    
    vector<string> ls(string path) {
        auto start = 0;
        auto end = path.find('/', start);
        Node* iter = this->root;

        // get path node
        string dirName;
        while (end < path.size()) {
            dirName = path.substr(start, end-start);
            if (!iter->subDirectory.count(dirName)) {
                return {};
            }
            iter = iter->subDirectory[dirName];
            start = end + 1;
            end = path.find('/', start);
        }
        dirName = path.substr(start, end-start);
        if (dirName.size()) {
            if (!iter->subDirectory.count(dirName))
                iter->subDirectory[dirName] = new Node();
            iter = iter->subDirectory[dirName];
        }

        // get all the materials
        vector<string> result;
        if (iter->hasFile) {
            result.push_back(dirName);
        }
        for (auto p : iter->subDirectory) {
            result.push_back(p.first);
        }
        sort(result.begin(), result.end());
        return result;
    }
    
    void mkdir(string path) {
        auto start = 0;
        auto end = path.find('/', start);
        Node* iter = this->root;

        string dirName;
        while (end < path.size()) {
            dirName = path.substr(start, end-start);
            if (!iter->subDirectory.count(dirName)) {
                iter->subDirectory[dirName] = new Node();
            }
            iter = iter->subDirectory[dirName];
            start = end + 1;
            end = path.find('/', start);
        }
        dirName = path.substr(start, end-start);
        if (!iter->subDirectory.count(dirName)) {
            iter->subDirectory[dirName] = new Node();
        }
    }
    
    void addContentToFile(string filePath, string content) {
        auto start = 0;
        auto end = filePath.find('/', start);
        Node* iter = this->root;

        string dirName;
        while (end < filePath.size()) {
            dirName = filePath.substr(start, end-start);
            if (!iter->subDirectory.count(dirName)) {
                iter->subDirectory[dirName] = new Node();
            }
            iter = iter->subDirectory[dirName];
            start = end + 1;
            end = filePath.find('/', start);
        }
        dirName = filePath.substr(start, end-start);
        if (!iter->subDirectory.count(dirName)) {
            iter->subDirectory[dirName] = new Node();
        }
        iter = iter->subDirectory[dirName];

        iter->content += content;
        iter->hasFile = true;
    }
    
    string readContentFromFile(string filePath) {
        auto start = 0;
        auto end = filePath.find('/', start);
        Node* iter = this->root;

        string dirName;
        while (end < filePath.size()) {
            dirName = filePath.substr(start, end-start);
            if (!iter->subDirectory.count(dirName)) {
                iter->subDirectory[dirName] = new Node();
            }
            iter = iter->subDirectory[dirName];
            start = end + 1;
            end = filePath.find('/', start);
        }
        dirName = filePath.substr(start, end-start);
        if (!iter->subDirectory.count(dirName)) {
            iter->subDirectory[dirName] = new Node();
        }
        iter = iter->subDirectory[dirName];
        return iter->content;
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

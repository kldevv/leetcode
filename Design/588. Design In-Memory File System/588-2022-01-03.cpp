// 2022/01/03

class FileSystem {
private:
    struct Node {
        string content;
        bool isFile;
        unordered_map<string, Node*> subdir;
        Node() {
            isFile = false;
            content = "";
        }
    };
    pair<Node*, string> traverse(string path) {
        if (path == "/") {
            return make_pair(root, "/");
        }
        Node* head = root;
        int start = 1;
        int end = 0;
        string name = "/";
        while (end < path.size()) {
            end = path.find_first_of('/', start);
            name = path.substr(start, end-start);
            if (head->subdir.count(name) == 0) {
                head->subdir[name] = new Node();
            }
            head = head->subdir[name];
            start = end + 1;
        }
        return make_pair(head, name);
    }
    Node* root;
public:
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        auto [head, name] = traverse(path);
        if (head->isFile) {
            return vector<string> { name };
        }
        vector<string> result;
        for (auto [name, iter] : head->subdir) {
            result.push_back(name);
        }
        sort(result.begin(), result.end());
        return result;
    }
    
    void mkdir(string path) {
        traverse(path);
    }
    
    void addContentToFile(string filePath, string content) {
        auto [head, name] = traverse(filePath);
        head->isFile = true;
        head->content += content;
    }

    
    string readContentFromFile(string filePath) {
        auto [head, name] = traverse(filePath);
        return head->content;
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
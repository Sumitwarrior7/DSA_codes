class Node {
    public:
        bool flag;
        vector<Node*> links; 
        Node() {
            links.resize(26, NULL);
            flag = false;
        }

        bool isCharPresent(char ch) {
            if(links[ch-'a'] == NULL) return false;
            else return true;
        }

        void insertChar(char ch) {
            links[ch-'a'] = new Node();
        }

        Node* getNode(char ch) {
            return links[ch-'a'];
        }
};


class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->isCharPresent(word[i]) == false) {
                node->insertChar(word[i]);
            }
            node = node->getNode(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->isCharPresent(word[i]) == false) {
                return false;
            }
            else {
                node = node->getNode(word[i]);
            }
        }
        if(node->flag == true) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++) {
            if(node->isCharPresent(prefix[i]) == false) {
                return false;
            }
            else {
                node = node->getNode(prefix[i]);
            }
        }
        return true;
    }
};
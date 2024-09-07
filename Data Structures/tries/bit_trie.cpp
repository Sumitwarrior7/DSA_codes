#define FOR(i, n) for(int i=0; i<n; i++)
#define IFOR(i, a, n) for(int i=a; i<n; i++)

class Node {
public:
    vector<Node*> links;
    int cnt;
    Node() {
        links.resize(2, NULL);
        cnt = 0;
    }

    bool check_bit(int bit) {
        if(links[bit]==NULL) return false;
        else return true;
    }

    Node* get_bit(int bit) {
        return links[bit];
    }

    void insert_bit(int bit) {
        if(links[bit]==NULL) links[bit] = new Node();
    }

    void change_cnt(int val) {
        cnt += val;
    }
};

class Trie {
public:
    Node* root;
    int tb;
    Trie() {
        root = new Node();
        tb = 22;
    }

    void insert_num(int num) {
        Node* temp = root;
        for(int i=tb-1; i>=0; i--) {
            int bit = ((num&(1<<i)) == 0)?0:1;
            if(temp->check_bit(bit) == false) temp->insert_bit(bit);
            temp = temp->get_bit(bit);
            (temp->cnt)++;
        }
    }

    void delete_num(int num) {
        Node* temp = root;
        for(int i=tb-1; i>=0; i--) {
            int bit = ((num&(1<<i)) == 0)?0:1;
            temp = temp->get_bit(bit);
            (temp->cnt)--;
        }
    }

    int get_max_xor(int num) {
        Node* temp = root;
        int ans = 0;
        for(int i=tb-1; i>=0; i--) {
            int num_bit = ((num&(1<<i)) == 0)?0:1;
            int tar_bit = 1-num_bit;
            if(temp->check_bit(tar_bit) == true && temp->get_bit(tar_bit)->cnt > 0) {
                ans += pow(2, i);
                temp = temp->get_bit(tar_bit);
            }
            else {
                temp = temp->get_bit(num_bit);
            }
        }
        return ans;
    }
};

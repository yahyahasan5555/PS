//https://leetcode.com/problems/replace-words/description/

class Trie {
private:
    static const int MAX_CHAR {26};
    Trie* child[MAX_CHAR] {};
    bool is_word_end {};
public:
    Trie() = default;
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const string& str) {
        Trie* cur {this};
        for(char c: str) {
                int cur_idx {c - 'a'};
                if(!cur->child[cur_idx]) cur->child[cur_idx] = new Trie();
                cur = cur->child[cur_idx];
        }
        cur->is_word_end = true;
    }

    string replace(const string& root) {
        string res;
        Trie* cur {this};

        for(int i {}; i < (int) root.size(); ++i) {
            int cur_idx {root[i] - 'a'};

            if(!cur->child[cur_idx])
                return root;
            
            res += root[i];
            if(cur->child[cur_idx]->is_word_end)
                return res;
        

            cur = cur->child[cur_idx];
        } return root;

    }

    ~Trie() {
        for(Trie* ch: child)
            delete ch;
    }
};



class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;

        for(string& str: dictionary)
            trie.insert(str);            
        
        istringstream iss(sentence);
        string str_in, res;
        while(iss>>str_in) {
            if(!res.empty()) res += ' ';
            res += trie.replace(str_in);
        }
        
        return res;
    }
};

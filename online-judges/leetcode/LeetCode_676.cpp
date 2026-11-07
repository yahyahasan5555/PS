// https://leetcode.com/problems/implement-magic-dictionary/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


class MagicDictionary {
       static const int MAX_CHAR {26}; // number of english letters
       MagicDictionary* child[MAX_CHAR] {}; // the {} is enough to initialize the whole array with nullptr
       bool is_end_word {false};

public:     
       MagicDictionary() = default;
       MagicDictionary(const MagicDictionary&) = delete;
       MagicDictionary& operator=(const MagicDictionary&) = delete;

       void insert(const string& word) {
              MagicDictionary* cur {this};
              for(const char& c: word) {
                     int cur_idx {c - 'a'};
                     if(!cur->child[cur_idx])
                            cur->child[cur_idx] = new MagicDictionary();
                     cur = cur->child[cur_idx];
              } cur->is_end_word = true;
       }

       void buildDict(const vector<string>& dictionary) {
              for(const string& word: dictionary)
                     this->insert(word);
       }
       
       bool search(const string& searchWord, int cur_idx = 0, bool is_try_used = false) {
              if(cur_idx == (int) searchWord.size())
                     return !is_try_used? false: this->is_end_word;
              
              bool res {false};
              for(int i {}; i < MAX_CHAR; ++i) {
                     if(!this->child[i]) continue;

                     int cur_char {searchWord[cur_idx] - 'a'};
                     if(i == cur_char)
                            res = res || this->child[i]->search(searchWord, cur_idx+1, is_try_used);
                     else if(!is_try_used) 
                            res = res || this->child[i]->search(searchWord, cur_idx+1, true);

                     if(res) return true;
              } 
              return false;
       }
};

void test1(void) {
       MagicDictionary* magicDictionary = new MagicDictionary();
       magicDictionary->buildDict({"hello","hallo","leetcode","judge", "judgg"});

       cout << magicDictionary->search("hello") << '\n';
       cout << magicDictionary->search("hallo") << '\n';
       cout << magicDictionary->search("hell") << '\n';
       cout << magicDictionary->search("leetcodd") << '\n';
       cout << magicDictionary->search("judge") << '\n';
       cout << magicDictionary->search("juggg") << '\n';

}

int main() {
       test1();
       return 0;
}      
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    map<string, int> wordmap;
    map<string, int> wordcount;
    int wordlen = 0;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()||words[0].empty()||s.empty()){
            return res;
        }
        int i;
        for(i = 0; i < words.size(); ++i){
            if(this->wordcount.find(words[i]) != this->wordcount.end()){
                this->wordcount[words[i]] += 1;
            }
            else this->wordcount[words[i]]= 1;
        }
        i = 0;
        for(const auto& pair : this->wordcount){
            this->wordmap[pair.first] = i++;
        }
        this->wordlen = words[0].length();
        for(i = 0; i <= (int)(s.size() - this->wordlen*words.size()); ++i){
            if(this->isPermutation(s.substr(i, this->wordlen*words.size()))){
                res.push_back(i);
            }
        }
        return res;
    }

    bool isPermutation(const string& s){
        vector<int> rec(s.length(), 0);
        for(int i = 0; i < s.size(); i += this->wordlen){
            if(wordmap.find(s.substr(i, this->wordlen))!=wordmap.end()){
                rec[this->wordmap[s.substr(i, this->wordlen)]]++;
            }
            else
                return false;
        }
        for(auto& pair:this->wordmap){
            if(this->wordcount[pair.first] != rec[pair.second])
                return false;
        }
        return true;
    }
};

int main(){
    string s = "aaaaaaaa";
    vector<string> words {"aa", "aa", "aa"};
    auto res = Solution().findSubstring(s, words);
    for(auto each:res){
        cout << each << ' ';
    }
    return 0;
}
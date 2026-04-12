#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());//for easier acess

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        s.erase(beginWord);//erase words if valid

        while(!q.empty()){
            auto [word, k] = q.front();
            q.pop();

            if(word == endWord) return k;

            for(int i = 0; i < word.size(); i++){
                char original = word[i];//store og letter

                for(char letter = 'a'; letter <= 'z'; letter++){//iterate
                    word[i] = letter;           //replace letter and make new word

                    if(s.find(word) != s.end()){        //if in wordlist
                        s.erase(word);
                        q.push({word, k + 1});
                    }
                }
                word[i] = original;         //revert to org
            }
        }
        return 0;               //if not found
    }
};

int main() {
    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    int result = obj.ladderLength(beginWord, endWord, wordList);

    cout << "Shortest transformation length: " << result << endl;

    return 0;
}
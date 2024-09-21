class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //create set 
        unordered_set<string> wordSet(wordList.begin(),wordList.end());

        if(wordSet.find(endWord)==wordSet.end()){
            return 0;
        }
        //create queue for bfs 
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        //BFS loop
        while(!q.empty()){
            auto [currentWord,level] = q.front();
            q.pop();

            for(int i = 0; i<currentWord.length(); i++){
                string temp = currentWord;

                for(char c = 'a'; c<='z'; c++){
                    temp[i] = c;

                    if(temp == endWord) return level+1;

                    if(wordSet.find(temp) != wordSet.end()){
                        q.push({temp,level+1});
                        wordSet.erase(temp);
                    }
                }
                
            }
        }
        return 0;
    }
};

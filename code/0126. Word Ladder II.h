/*
Given two words (beginWord and endWord), and a dictionary's word list, 
find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
    //返回是否只变了一个
    bool helper(string &s1, string &s2){
        bool res=true;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(res) res=false;
                else return res;
            }
        }
        return !res;
    }
    int add(vector<string> &words, string word){
        for(int i=0;i<words.size();i++)
            if(words[i]==word) return i;
        words.push_back(word);
        return words.size()-1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int start=add(wordList,beginWord);
        int tempSize=wordList.size();
        int end=add(wordList,endWord);
        if(end==tempSize) return res;
        
        //找下一层时加入临时的visited，找完下一层时真正加入，因为scan相同的层不能变visited
        vector<int> visited(wordList.size(),0); 
        
        queue<vector<int>> q;
        q.push({start});
        visited[start]=1;
        bool find=false;
        while( !find && !q.empty()){
            int n=q.size();
            set<int> tempVisited;
            unordered_map<int,vector<int>> nexts; //在这层的末尾出现过，已经找过next
            for(int k=0;k<n;k++){
                vector<int> cur=q.front();
                q.pop();
                int last=cur[cur.size()-1];
                //出现在path尾部过
                if(nexts.count(last)){
                    if(nexts[last].size()==1 && nexts[last][0]==-1)
                        continue;
                    for(auto i:nexts[last]){
                        vector<int> temp=cur;
                        temp.push_back(i);
                        if(i!=end){
                            if(!find)
                                q.push(temp);
                        }
                        else{
                            find=true;
                            res.push_back(vector<string>());
                            for(auto j:temp){
                                res.back().push_back(wordList[j]);
                            }
                        }
                    }
                }
                //没有出现过，找下一个
                else{
                    for(int i=0;i<wordList.size();i++){
                        if(i==last|| visited[i]) continue;
                        if(helper(wordList[last],wordList[i])){
                            nexts[last].push_back(i);
                            tempVisited.insert(i);
                            vector<int> temp=cur;
                            temp.push_back(i);
                            if(i!=end){
                                if(!find)
                                    q.push(temp);
                            }
                            else{
                                find=true;
                                res.push_back(vector<string>());
                                for(auto j:temp){
                                    res.back().push_back(wordList[j]);
                                }
                            }
                        }
                    }
                    if(nexts.count(last)==0)
                        nexts[last].push_back(-1);
                }
            }
            if(!find)
                for(auto i:tempVisited)
                    visited[i]=true;
        }
        return res;
    }
};

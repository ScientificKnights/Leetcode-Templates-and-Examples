/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences.

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[  "cats and dog",  "cat sand dog"  ]
*/

class Solution {
private:
    //top down dp, save data
    unordered_map<string,vector<string>> data;
    
    vector<string> helper(string s, unordered_set<string>& Dict) {
        //avoid called before
        if(data.count(s))
            return data[s];
        
        data[s]={};//create one even if there is no solution, avoid call again
        for(int i=0;i<s.size();i++){
            if(Dict.count(s.substr(i))){
                string prev=s.substr(0,i);
                for(auto j: helper(prev,Dict))
                    data[s].emplace_back( j+((j=="")?"":" ")+s.substr(i));
            }
        }
        return data[s];
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict(wordDict.begin(),wordDict.end());
        data[""].push_back("");     //start from empty
        return helper(s, Dict);
    }
};

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
*/

    bool wordBreak(string s, vector<string>& wordDict) {
        //set<string> data(wordDict);
        //set faster to find, better than vector.
        set<string> data(wordDict.begin(),wordDict.end());
        
        int n=s.size();
        vector<bool> res(n+1);
        res[0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<i;j++){
                if(res[i]==true) 
                    break;
                res[i]=res[j] && data.find(s.substr(j,i-j))!=data.end();
            }
        }
        return res[n];
    }

/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
*/

int numMatchingSubseq(string S, vector<string>& words) {
    int n=S.size(),res=0;
    vector<vector<int>> data(26,vector<int>());
    for(int i=0;i<n;i++)
        data[S[i]-'a'].push_back(i);
    for(int i=0;i<words.size();i++){
        int prev=-1;
        for(int j=0;j<words[i].size();j++){
            auto cur=upper_bound(data[words[i][j]-'a'].begin(),data[words[i][j]-'a'].end(),prev);
            if(cur!=data[words[i][j]-'a'].end() )
                prev=(*cur);
            else break;

            if(j==words[i].size()-1) res++;
        }
    }
    return res;
}

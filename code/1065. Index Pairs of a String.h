/*
Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] 
is in the list of words.

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]

Note:

All strings contains only lowercase English letters.
It's guaranteed that all strings in words are different.
1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
Return the pairs [i,j] in sorted order (i.e. sort them by their first coordinate in case of ties sort them 
by their second coordinate).
*/

vector<vector<int>> indexPairs(string text, vector<string>& words) {
    vector<vector<int>> res;
    for(int i=0;i<words.size();i++){
        int start=0;
        auto pos=text.find(words[i],start);
        while(pos!=string::npos){
            res.push_back({pos,-1+pos+words[i].size()});
            start=pos+1;
            pos=text.find(words[i],start);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

/*
Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Input: s = "aabbcc", k = 3
Output: "abcabc" 
Explanation: The same letters are at least distance 3 from each other.

Input: s = "aaabc", k = 3
Output: "" 
Explanation: It is not possible to rearrange the string.

Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least distance 2 from each other.
*/

string rearrangeString(string s, int k) {
    if(k<=1) return s; //"a",k=0
    int left=s.size();
    vector<int> count(26,0);
    for(auto i:s) count[i-'a']++;
    priority_queue<pair<int, char>> q;
    for(int i=0;i<26;i++)
        if(count[i]!=0)
            q.push({count[i],'a'+i});
    string res;
    while(left>0){
        int len=min(k,left);
        vector<pair<int,char>> data;
        //data 存储 top k freq
        for(int i=0;i<len;i++,left--){
            if(q.empty()) return ""; //有不是1的，并且不同类别的不够了
            data.push_back(q.top());
            q.pop();
            data.back().first--;
            res.push_back(data.back().second);
        }
        for(int i=0;i<len;i++)
            if(data[i].first)
                q.push(data[i]);
    }
    return res;
}

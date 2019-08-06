/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> 
to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together 
by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"

s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"

Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
*/

class Solution {
private:
    vector<vector<int>> helper(map<int,int> &intervals){
        vector<vector<int>> res;
        bool flag=false;
        int sum=0;
        for(auto i:intervals){
            sum+=i.second;
            if(!flag && sum>0){
                res.push_back({i.first});
                flag=true;
            }
            else if(sum==0){
                res.back().push_back(i.first);
                flag=false;
            }
        }
        return res;
    }
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n=s.size(), m=dict.size();
        map<int,int> intervals;
        for(int i=0;i<m;i++){
            int pos=0;
            while(pos!=string::npos){
                pos=s.find(dict[i],pos);
                if(pos!=string::npos){
                    intervals[pos]++;
                    intervals[pos+dict[i].size()]--;
                    pos++;
                }
            }
        }
        vector<vector<int>> upper=helper(intervals);

        string res;
        int start=0;
        for(auto i:upper){
            if(start<i[0])
                res+=s.substr(start,i[0]-start);
            res+=("<b>"+s.substr(i[0],i[1]-i[0])+"</b>");
            start=i[1];
        }
        if(start<n) res+=s.substr(start);
        return res;
    }
};

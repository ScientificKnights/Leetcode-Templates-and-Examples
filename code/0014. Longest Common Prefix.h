/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Input: ["flower","flow","flight"]
Output: "fl"

Input: ["dog","racecar","car"]
Output: ""

All given inputs are in lowercase letters a-z.
*/

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0)
        return "";
    int max=0;
    string s="";
    while(true){
        if(max<strs[0].size()){
            char c=strs[0][max];
            for (int i=1;i<strs.size();i++){
                if (strs[i].size()<=max || strs[i][max]!=c)
                    return s;
                }
            max++;
            s+=c;
        }
        else
            return s;
    }
}

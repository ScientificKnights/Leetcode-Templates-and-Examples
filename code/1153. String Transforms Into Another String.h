/*
Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.
In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.
Return true if and only if you can transform str1 into str2.

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
*/

    bool canConvert(string str1, string str2) {
        vector<vector<int>> pos1(26,vector<int>());
        for(int i=0;i<str1.size();i++)
            pos1[str1[i]-'a'].push_back(i);
        unordered_map<int,int>pos2;
        for(int i=0;i<str2.size();i++) 
            pos2[i]=str2[i]-'a';
        for(int i=0;i<26;i++){
            if(!pos1[i].size()) continue;
            int find=pos2[pos1[i][0]];
            for(int j=1;j<pos1[i].size();j++)
                if(pos2[pos1[i][j]]!=find) return false;
        }
        
        //case: abc...z => zabc..y
        vector<int> visited1(26,0),visited2(26,0);
        int count1=0,count2=0;
        for(auto i:str1){
            visited1[i-'a']++;
            if(visited1[i-'a']==1) count1++;
        }
        for(auto i:str2){
            visited2[i-'a']++;
            if(visited2[i-'a']==1) count2++;
        }
        if(count1==26 && count2==26 && str1!=str2) return false;
        
        return true;
    }

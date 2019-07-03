/*

Find the length of the longest substring T of a given string (consists of lowercase letters only) 
such that every character in T appears no less than k times.

Input:
s = "aaabb", k = 3
Output:
3

Input:
s = "ababbc", k = 2
Output:
5
*/

int longestSubstring(string s, int k) {
    //aaabaa k=2, 种类过多有的不够k。2种
    //ababab k=2, 种类过少不能加入混合但。1种
    int n=s.size(), res=0;
    for(int type=1;type<=26;type++){
        int start=0, count_type=0, count_k=0;
        vector<int> count(26,0);
        for(int end=0; end<n; end++){
            count[s[end]-'a']++;
            if(count[s[end]-'a']==1) count_type++;
            if(count[s[end]-'a']==k) count_k++;
            if(count_type==count_k) res=max(res,end-start+1);
            while(count_type>type){
                count[s[start]-'a']--;
                if(count[s[start]-'a']==0) count_type--;
                if(count[s[start]-'a']==k-1) count_k--;
                start++;
            }
        }
    }
    return res;
}

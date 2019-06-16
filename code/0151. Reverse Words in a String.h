/*
Given an input string, reverse the string word by word.

Input: "the sky is blue"
Output: "blue is sky the"

Input: "  hello world!  "
Output: "world! hello"

Input: "a good   example"
Output: "example good a"
*/

string reverseWords(string s) {
    int pos=0,start=0, n=s.size();

    string res;
    while(s[start]==' ') start++;
    //" a    a "
    for(int i=start;i<n;i++){
        if(s[i]==' '){
            if(res[res.size()-1]!=' ') 
                res+=' ';
        }
        else
            res+=s[i];
    }

    //"aa "
    if(res[res.size()-1]==' ') res.pop_back();
    n=res.size();

    for(int i=0;i<=n;i++){
        if(i==n || res[i]==' '){
            reverse(res.begin()+pos,res.begin()+i);
            pos=i+1;
        }
    }
    reverse(res.begin(),res.end());

    return res;
}

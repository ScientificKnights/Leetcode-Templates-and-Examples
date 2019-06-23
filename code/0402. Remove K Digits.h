/*
Given a non-negative integer num represented as a string, remove k digits from the number 
so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Input: num = "1432219", k = 3
Output: "1219"
*/

string removeKdigits(string num, int k) {
    int n=num.size(), i=0;
    string s="";
    for(;i<n && k>0;i++){
        if(!s.size()|| num[i]>=s.back()) s+=(num[i]);
        else{
            while(k>0 && s.size() && s.back()>num[i]){
                s.pop_back();
                k--;
            }
            s+=(num[i]);
        }
    }

    if(i<n)     //already got k
        s+=num.substr(i);
    //haven't got k
    s=s.substr(0,s.size()-k);

    i=0;
    while(i<s.size()-1 && s[i]=='0') i++;   //remove 0, not including last one
    return s.size()?s.substr(i): "0";
}

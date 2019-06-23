/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

Input: num1 = "2", num2 = "3"
Output: "6"

Input: num1 = "123", num2 = "456"
Output: "56088"
*/

string multiply(string num1, string num2) {
    int n=num1.size(),m=num2.size();
    vector<int> data(n+m,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            data[n-1+m-1-i-j]+=((num1[i]-'0')*(num2[j]-'0'));
        }
    string res;
    for(int i=0;i<n+m;i++){
        res+= (data[i]%10+'0');
        if(i!=n+m-1)
            data[i+1]+=(data[i]/10);
    }
    //remove 0s
    n=res.size()-1;
    while(n>=1 && res[n]=='0'){
        n--;
    }
    res=res.substr(0,n+1);
    reverse(res.begin(),res.end());
    return res;
}

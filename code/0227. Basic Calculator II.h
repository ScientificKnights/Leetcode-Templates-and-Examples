/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
The integer division should truncate toward zero.

Input: "3+2*2"
Output: 7

Input: " 3/2 "
Output: 1

Input: " 3+5 / 2 "
Output: 5

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

int calculate(string s) {
    int n=s.size();
    stack<int> s1;stack<char> s2;
    for(int i=0;i<n;){
        if(s[i]==' '){i++;continue;}
        else if(!isdigit(s[i])){s2.push(s[i++]);}
        else{
            int j=i;
            while(isdigit(s[j])) j++;
            int num=stoi(s.substr(i,j-i));
            if(!s2.empty() && (s2.top()=='*'||s2.top()=='/')){
                if(s2.top()=='*') s1.top()*=num;
                else s1.top()/=num;
                s2.pop();
            }
            else s1.push(num);
            i=j;
        }
    }
    int res=0;
    while(!s2.empty()){
        if(s2.top()=='+')
            res+=s1.top();
        else
            res-=s1.top();
        s1.pop();
        s2.pop();
    }
    return res+s1.top();
}

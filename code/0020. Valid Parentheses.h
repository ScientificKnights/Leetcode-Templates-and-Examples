/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Input: "()"
Output: true

Input: "()[]{}"
Output: true

Input: "(]"
Output: false

Input: "([)]"
Output: false

Input: "{[]}"
Output: true
*/
bool isValid(string s) 
{
    stack<char> data;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            data.push(s[i]);
        else
        {
            if(s[i]==')')
            {
                if(!data.empty()&&data.top()=='(')      //data 可能为空
                    data.pop();
                else
                    return false;
            }
            else if(s[i]==']')
            {
                if(!data.empty()&&data.top()=='[')
                    data.pop();
                else
                    return false;
            }
            else
            {
                if(!data.empty()&&data.top()=='{')
                    data.pop();
                else
                    return false;
            }
        }
    }
    if(data.empty())    return true;
    else return false;
}

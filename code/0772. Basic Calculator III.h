/*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . 
The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
*/

class Solution {
private:
    //put a number into stack
    void add_num(vector<stack<long>> &s1,vector<stack<char>> &s2, int num){
        if(!s2.back().empty() && (s2.back().top()=='*'||s2.back().top()=='/')){
            if(s2.back().top()=='*') s1.back().top()*=num;
            else s1.back().top()/=num;
            s2.back().pop();
        }
        else s1.back().push(num);
        return;
    }
    
    //calcuate last line of vector, no * and / in stacks
    long calculate_no_parentheses(vector<stack<long>> &s1,vector<stack<char>> &s2){
        long num=0;
        while(!s2.back().empty()){
            if(s2.back().top()=='+')
                num+=s1.back().top();
            else
                num-=s1.back().top();
            s1.back().pop();
            s2.back().pop();
        }
        num+=s1.back().top();
        return num;
    }
public:
    int calculate(string s) {
        int n=s.size();
        vector<stack<long>> s1;
        vector<stack<char>> s2;
        s1.push_back(stack<long>()),s2.push_back(stack<char>());
        
        for(int i=0;i<n;){
            if(s[i]==' '){i++;continue;}
            else if(s[i]=='('){
                s1.push_back(stack<long>()),s2.push_back(stack<char>());
                i++;
            }
            else if(s[i]==')'){
                long num=calculate_no_parentheses(s1,s2);
                s1.pop_back(),s2.pop_back();
                add_num(s1,s2,num);
                i++;
            }
            else if(!isdigit(s[i])){s2.back().push(s[i++]);}
            else{
                int j=i;
                while(isdigit(s[j])) j++;
                long num=stol(s.substr(i,j-i));
                add_num(s1,s2,num);
                i=j;
            }
        }
        return (int)calculate_no_parentheses(s1,s2);
    }
};

/*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Input: "1 + 1"
Output: 2

Input: " 2-1 + 2 "
Output: 3

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

class Solution {
private:
    //calcuate last line of vector, no * and / in stacks
    int calculate_no_parentheses(vector<stack<int>> &s1,vector<stack<char>> &s2){
        int num=0;
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
        vector<stack<int>> s1;
        vector<stack<char>> s2;
        s1.push_back(stack<int>()),s2.push_back(stack<char>());
        
        for(int i=0;i<n;){
            if(s[i]==' '){i++;continue;}
            else if(s[i]=='('){
                s1.push_back(stack<int>()),s2.push_back(stack<char>());
                i++;
            }
            else if(s[i]==')'){
                int num=calculate_no_parentheses(s1,s2);
                s1.pop_back(),s2.pop_back();
                s1.back().push(num);
                i++;
            }
            else if(!isdigit(s[i])){s2.back().push(s[i++]);}
            else{
                int j=i;
                while(isdigit(s[j])) j++;
                int num=stoi(s.substr(i,j-i));
                s1.back().push(num);
                i=j;
            }
        }
        return calculate_no_parentheses(s1,s2);
    }
};

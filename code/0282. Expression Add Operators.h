/*
Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"] 

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]
*/

class Solution {
private:
    void backtrack(vector<string> & res, string num, string &path, long long prev,long long tot,int target){
        if(!num.size()){
            if(tot==(long long) target) res.emplace_back(path);
            return;
        }
        for(int i=1;i<=num.size();i++){
            long long cur=stoll(num.substr(0,i));
            if(num[0]=='0' && i>1) return;  // "105" 5 除去 1*05
            int n=path.size();
            if(n){
                path=path+'+'+num.substr(0,i);
                backtrack(res,num.substr(i),path,cur,tot+cur,target);
                path[n]='-';
                backtrack(res,num.substr(i),path,-cur,tot-cur,target);
                path[n]='*';
                backtrack(res,num.substr(i),path,prev*cur,(tot-prev)+prev*cur,target);
                path=path.substr(0,n);
            }
            else{
                path=num.substr(0,i);
                backtrack(res,num.substr(i),path,cur,cur,target);
                path="";
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        // +-*part one and backtrack part two
        vector<string> res;
        string path="";
        backtrack(res,num,path,0,0,target);
        return res;
    }
};

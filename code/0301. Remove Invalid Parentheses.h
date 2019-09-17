/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ).


Input: "()())()"
Output: ["()()()", "(())()"]

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Input: ")("
Output: [""]
*/

void dfs(vector<string> &res, string s, int pos,int lastRm, string dir){
    //看不懂这个最优答案
    for(int i=pos,count=0;i<s.size();i++){
        if(s[i]==dir[0]) count++;
        else if(s[i]==dir[1]) count--;
        if(count>=0) continue;

        //从上一次remove的开始，到i，多一个的位置
        for(int j=lastRm;j<=i;j++){
            if(s[j]==dir[1] && (j==lastRm || s[j-1]!=dir[1]))   // && 后面去重复的
                dfs(res,s.substr(0,j)+s.substr(j+1),i,j,dir); //新的i是count=0的位置了，j是remove后的下一位
        }
        return;
    }
    reverse(s.begin(),s.end());
    //一个都没remove才能走到这
    if(dir[0]=='(') dfs(res,s,0,0,")(");
    else res.push_back(s);  //只有 ")(" 一次没remove才能走到这
}
public:
vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    dfs(res,s,0,0,"()");
    return res;
}

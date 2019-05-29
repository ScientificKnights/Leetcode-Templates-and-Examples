/*
Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, 
return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.

Input: S = "0110", N = 3
Output: true
*/

bool queryString(string S, int N) {
    //7  3,2,1 检查过了
    for(int i=N;i>N/2;i--){
        string n=bitset<32>(i).to_string(); //不能用std的to_string
        if(S.find(n.substr(n.find('1')))==string::npos) 
            return false;
    }
    return true;
}

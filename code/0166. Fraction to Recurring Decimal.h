/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.


Input: numerator = 1, denominator = 2
Output: "0.5"

Input: numerator = 2, denominator = 1
Output: "2"

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

class Solution {
    string helper(long long n,long long m){
        unordered_map<long long,int> nToPos; //map n to position start recurring
        string s;
        int pos=0;
        while(n!=0){
            if(nToPos.count(n))
                return s.substr(0,nToPos[n])+'('+s.substr(nToPos[n])+')';
            nToPos[n]=pos++;
            s+=(10*n)/m+'0';
            n=(10*n)%m;
        }
        return s;
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        //INT_MIN overflow
        long long n=numerator, m=denominator;
        if(n%m==0) return to_string(n/m);
        //分开处理符号
        string sign= ((abs(n)/n) * (abs(m)/m)==1)?"":"-";
        n=abs(n),m=abs(m);
        return sign+to_string(n/m)+'.'+helper(abs(n%m),m);  // -50 /8
    }
};

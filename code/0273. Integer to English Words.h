/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Input: 123
Output: "One Hundred Twenty Three"

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/

class Solution {
    string helper(int n){
        if(n>=1000000000) return helper(n/1000000000)+" Billion"+helper(n%1000000000);
        else if(n>=1000000) return helper(n/1000000)+" Million"+helper(n%1000000);
        else if(n>=1000) return helper(n/1000)+" Thousand"+helper(n%1000);
        else if(n>=100) return helper(n/100)+" Hundred"+helper(n%100);
        else if(n>=20) return " "+below100[n/10-2]+helper(n%10);
        else if(n>=1) return " "+below20[n-1];
        else return "";
    }
public:
    const vector<string> below20={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
            "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const vector<string> below100={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string numberToWords(int num) {
        if(num==0) return "Zero";
        return helper(num).substr(1);
    }
};

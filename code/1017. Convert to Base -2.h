/*
Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).
The returned string must have no leading zeroes, unless the string is "0".

Output: "110"
Explantion: (-2) ^ 2 + (-2) ^ 1 = 2
*/

string baseNeg2(int N, string res = "") {
    while (N != 0) {
        int rem = N % -2;
        N /= -2;
        if (rem < 0) 
            rem += 2, N += 1;
        res = to_string(rem) + res;
    }
    return max(string("0"), res);
}

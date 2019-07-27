/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

string convert(string s, int numRows) {
    string result;
    int n=s.size();
    if(numRows==1 || n<=numRows)  return s;
    int new_p=numRows*2-2;
    for(int i=0;i<n;i+=new_p)
        result+=s[i];
    for(int i=1;i<numRows-1;i++)
        for(int j=i;j<n ;j+=new_p){
            result+=s[j];
            if(j+new_p-2*i<n)
                result+=s[j+new_p-2*i];
        }
    for(int i=numRows-1;i<n;i+=new_p)
        result+=s[i];
    return result;
}

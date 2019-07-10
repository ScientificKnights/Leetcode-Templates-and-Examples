/*
Given an array of characters, compress it in-place.
The length after compression must always be smaller than or equal to the original array.
Every element of the array should be a character (not int) of length 1.
After you are done modifying the input array in-place, return the new length of the array.

Input:
["a","a","b","b","c","c","c"]
Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Input:
["a"]
Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/

int compress(vector<char>& chars) {
    //abc
    //aabbccc
    int start=0,end=1,n=chars.size(),count=1;
    for(;end<=n;){  // = make "a" and "abc" can pass
        while(end<n && chars[end]==chars[end-1]) {
            count++;
            end++;
        }
        chars[start++]=chars[end-1];
        if(count>1) {
            string val=to_string(count);
            for(int i=0;i<val.size();i++){
                chars[start++]=val[i];
            }
        }
        count=1;
        end++;
    }
    return start;
}

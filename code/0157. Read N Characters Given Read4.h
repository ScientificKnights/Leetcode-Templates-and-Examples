/*
Given a file and assume that you can only read the file using a given method read4, implement a method to read n characters.

Method read4:
The API read4 reads 4 consecutive characters from the file, then writes those characters into the buffer array buf.
The return value is the number of actual characters read.
Note that read4() has its own file pointer, much like FILE *fp in C.

Definition of read4:

    Parameter:  char[] buf
    Returns:    int

Note: buf[] is destination not source, the results from read4 will be copied to buf[]
Below is a high level example of how read4 works:

File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
char[] buf = new char[4]; // Create buffer with enough space to store characters
read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file
 

Method read:

By using the read4 method, implement the method read that reads n characters from the file and store it in the buffer array buf. Consider that you cannot manipulate the file directly.

The return value is the number of actual characters read.

Definition of read:

    Parameters:	char[] buf, int n
    Returns:	int

Note: buf[] is destination not source, you will need to write the results to buf[]
 

Example 1:

Input: file = "abc", n = 4
Output: 3

Input: file = "abcde", n = 5
Output: 5

Input: file = "abcdABCD1234", n = 12
Output: 12

Input: file = "leetcode", n = 5
Output: 5
Note:

Consider that you cannot manipulate the file directly, the file is only accesible for read4 but not for read.
The read function will only be called once for each test case.
You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
/*
Given a file = "abc", and a destination buffer, buf = ["", "", "", ..... ]
after calling read(buf, 4), we will have: output = 3
and the destination buffer becomes buf = ["a", "b", "c", "", "", "", .......]
Because the read(buf, 4) function copied 4 characters (but there are only 3 in the file) from the file into the destination buffer
*/
    int read(char *buf, int n) {
        int res=0; 
        while(n>0){
            int num=min(read4(buf+res),n);
            res+=num;
            if(num<4) break;
            n-=4;
        }
        return res;
    }
};

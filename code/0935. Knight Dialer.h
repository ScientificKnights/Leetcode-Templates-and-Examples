/*
A chess knight can move as indicated in the chess diagram below:

https://assets.leetcode.com/uploads/2018/10/30/keypad.png

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  
Each hop must be from one key to another numbered key.
Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, 
pressing N digits total.
How many distinct numbers can you dial in this manner?
Since the answer may be large, output the answer modulo 10^9 + 7.
*/

int knightDialer(int N) {
    vector<vector<int>> path={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4},{4,6}} ;
    vector<int> prev(10,1);
    for(int n=2;n<=N;n++){
        vector<int> cur(10,0);
        for(int i=0;i<10;i++)
            for(auto j:path[i])
                cur[i]=(cur[i]+prev[j])%1000000007;
        prev=cur;
    }
    int res=0;
    for(auto i:prev){
        res=(res+i)%1000000007;
    }
    return res;
}

/*
You are given an integer array A.  From some starting index, you can make a series of jumps. 
The (1st, 3rd, 5th, ...) jumps in the series are called odd numbered jumps, 
and the (2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.

You may from index i jump forward to index j (with i < j) in the following way:

During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
(It may be the case that for some index i, there are no legal jumps.)
A starting index is good if, starting from that index, you can reach the end of the array (index A.length - 1) 
by jumping some number of times (possibly 0 or more than once.)

Return the number of good starting indexes.
*/

int oddEvenJumps(vector<int>& A) {
    int n=A.size(),res=1;
    if(n<2) return n;
    vector<vector<int>> dp(2,vector<int>(n,0));     //even, odd two states
    dp[0][n-1]=dp[1][n-1]=1;

    //set<pair<int,int>> s;     //binary search value -> position
    map<int,int> m;             //better,  如果相同，前面的可以覆盖后面的 
    m[A[n-1]]=n-1;
    for(int i=n-2;i>=0;i--){
        auto ii=m.lower_bound(A[i]);
        if(ii!=m.end())
            dp[0][i]=dp[1][ii->second];

        auto oo=m.upper_bound(A[i]);
        if(oo!=m.begin())       //2 3 1 1 4
            dp[1][i]=dp[0][prev(oo)->second];

        res+=((dp[0][i])?1:0);
        m[A[i]]=i;
        //cout<<dp[0][i]<<dp[1][i]<<endl;
    }
    return res;
}

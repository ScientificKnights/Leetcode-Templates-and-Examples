/*
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, 
then the final array after deletions is ["bef","vyz"].

Suppose we chose a set of deletion indices D such that after deletions, 
the final array has its elements in lexicographic order (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).

Return the minimum possible value of D.length.
*/
int minDeletionSize(vector<string>& A) {
    //count: how many row sorted
    //res: how many col deleted
    int n=A.size(),count=0,res=0;

    vector<int> ordered(n,0);   // 后续但值可以比下一个大不
    for(int i=0;i<A[0].size();i++){
        vector<int> temp_ordered=ordered;
        int temp_count=0;
        bool flag=1;    //stop if delete
        for(int j=0;j<n-1 && flag;j++){
            if(temp_ordered[j]) continue;
            if(A[j][i]<A[j+1][i]){
                temp_ordered[j]=1;
                temp_count++;
            }
            else if(A[j][i]>A[j+1][i]){
                res++;
                flag=0;
            }
        }
        if(flag){
            ordered=temp_ordered;
            count+=temp_count;
        }
        if(count==n-1) return res;  //all sorted
    }
    return res;
}

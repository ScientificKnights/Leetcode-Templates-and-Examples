/*
Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  
The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

Input: [6,0,8,2,1,5]
Output: 4

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
*/

int maxWidthRamp(vector<int>& A) {
    stack<int> s;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(s.empty() || A[s.top()]> A[i]) 
            s.push(i);
    }
    int res=0;
    for(int i=n-1;!s.empty() && i>res;i--){
        while(!s.empty() && A[s.top()]<=A[i]){
            res=max(res,i-s.top());
            s.pop();
        }
    }
    return res;
}

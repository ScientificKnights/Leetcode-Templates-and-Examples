/*
We have two integer sequences A and B of the same non-zero length.
We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.
At the end of some number of swaps, A and B are both strictly increasing.
(A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)
Given A and B, return the minimum number of swaps to make both sequences strictly increasing.
It is guaranteed that the given input always makes it possible.
*/

int minSwap(vector<int>& A, vector<int>& B) {
    //          3 3 4 5 7
    //          2 4 5 6 6
    //swap      1 1 2 3 2
    //no_swap   0 1 1 1 3
    int n=A.size();
    if(n<=1) return 0;
    int swap=1,no_swap=0;
    //two states, exchange and no exchange.
    //1. 不管换不换都行  2. 换才行 3. 不用换
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1] && A[i]>B[i-1] && B[i]>B[i-1] && B[i]>A[i-1]){
            int pre_swap=swap;
            swap=min(pre_swap,no_swap)+1;
            no_swap=min(pre_swap,no_swap);
        }
        else if(A[i]>A[i-1] && B[i]>B[i-1])
            swap++;
        else{
            int pre_swap=swap;
            swap=no_swap+1;
            no_swap=pre_swap;
        }

    }
    return min(swap,no_swap);
}

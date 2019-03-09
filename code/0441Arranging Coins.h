/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.

n = 5
The coins can form the following rows:
¤
¤ ¤
¤ ¤
Because the 3rd row is incomplete, we return 2.

n = 8
The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.
*/

int arrangeCoins(int n) {
    if(n<=1) return n;
    long long m=n;
    int l=1,r=sqrt(2*m)+1,mid;              //不能从n开始，sum会越界
    while(l<r){
        mid=l+(r-l)/2;
        long long sum;
        
        if(mid%2==0) sum=mid/2*(mid+1);     //防止越界
        else sum=(mid+1)/2*mid;
        
        if(sum>n) r=mid;
        else l=mid+1;
    }
    return l-1;
}

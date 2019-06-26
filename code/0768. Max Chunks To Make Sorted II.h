/*
This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, 
the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), 
and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Input: arr = [5,4,3,2,1]
Output: 1

Input: arr = [2,1,3,4,4]
Output: 4
*/

int maxChunksToSorted(vector<int>& arr) {
    //3 2 2 1 3 1 3 4
    //1 1 2 2 3 3 3 4
    int n=arr.size(),res=0;
    long long sum1=0,sum2=0;
    vector<int> s=arr;
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        sum1+=arr[i],sum2+=s[i];
        if(sum1==sum2) res++;
    }
    return res;
}

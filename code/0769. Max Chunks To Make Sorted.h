/*
Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], 
we split the array into some number of "chunks" (partitions), and individually sort each chunk.  
After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Input: arr = [4,3,2,1,0]
Output: 1

Input: arr = [1,0,2,3,4]
Output: 4
*/

int maxChunksToSorted(vector<int>& arr) {
    int n=arr.size(),res=0,longest=-1;
    for(int i=0;i<n;i++){
        if(i>longest){
            res++;
            longest=arr[i];
        }
        else
            longest=max(longest,arr[i]);
    }
    return res;
}

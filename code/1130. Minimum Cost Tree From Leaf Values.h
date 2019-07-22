/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  
(Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  
It is guaranteed this sum fits into a 32-bit integer.

Input: arr = [6,2,4]
Output: 32

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 
Constraints:
2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).
*/

int mctFromLeafValues(vector<int> arr) {
    // monotonic increading stack O(n) 也可以
    int n=arr.size();
    if(n<=1) return 0;
    int mi=INT_MAX,mi_index=-1;
    for(int i=0;i<n-1;i++){
        if(arr[i]*arr[i+1]<mi){
            mi=arr[i]*arr[i+1];
            mi_index=i;
        }
    }
    int res=mi;
    if(arr[mi_index+1]<arr[mi_index]) mi_index++;
    arr.erase(arr.begin()+mi_index);
    return res+mctFromLeafValues(arr);
}

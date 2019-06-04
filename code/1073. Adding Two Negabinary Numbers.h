/*

Given two numbers arr1 and arr2 in base -2, return the result of adding them together.
Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  
For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  
A number arr in array format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.
*/

vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    if(arr1.size()>arr2.size()) return addNegabinary(arr2,arr1);
    int n=arr1.size(),m=arr2.size();
    for(int i=0;i<n;i++){
        arr2[m-1-i]+=arr1[n-1-i];
    }
    reverse(arr2.begin(),arr2.end());
    arr2.push_back(0);arr2.push_back(0); //4 倍，足够相加后

    for(int i=0;i<m+1;i++){
        arr2[i+1]-=(arr2[i]>>1);
        arr2[i]=(arr2[i]&1);
    }
    for(int i=m+1;i>=0;i--){
        if(arr2[i]) break;
        else arr2.erase(arr2.begin()+i);
    }
    reverse(arr2.begin(),arr2.end());
    return arr2.size()?arr2: vector<int>{0};
}

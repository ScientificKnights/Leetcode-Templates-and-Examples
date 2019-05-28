/*
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.

Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]
*/

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int n=barcodes.size();
    unordered_map<int,int> m;
    for(auto i:barcodes) m[i]++;
    set<pair<int,int>> s;
    for(auto i:m) s.insert({i.second,i.first});
    vector<int> res(n);
    int pos=0;
    for(auto ii=s.rbegin(); ii!=s.rend();++ii){
        for(int i=0;i< (*ii).first;i++){
            if(pos>=n) pos=1;
            res[pos]=(*ii).second;
            pos+=2;
        }
    }
    return res;
}

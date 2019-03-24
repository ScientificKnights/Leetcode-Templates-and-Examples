/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is 
greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    //lambda
    sort(envelopes.begin(),envelopes.end(),[](pair<int,int> a, pair<int,int> b){
        return (a.first<b.first)||(a.first==b.first && a.second>b.second);});
    //6,7 before 6,4 
    vector<int> sorted;
    for (auto ii: envelopes){
        auto iter=lower_bound(sorted.begin(),sorted.end(),ii.second);
        if(iter==sorted.end())
            sorted.push_back(ii.second);
        else
            *iter=ii.second;
    }
    return sorted.size();
}

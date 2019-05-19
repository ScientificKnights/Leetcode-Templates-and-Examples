/*
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

Input: "abbaca"
Output: "ca"
*/

string removeDuplicates(string S) {
    string res="";
    for(auto i:S){
        if(res.size()&&res.back()==i) res.pop_back();
        else res+=i;
    }
    return res;
}

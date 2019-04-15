/*
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, 
and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person 
if there is some email that is common to both accounts. Note that even if two accounts have the same name, 
they may belong to different people as people could have the same name. A person can have any number of accounts initially, 
but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, 
and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], 
            ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
                        ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
*/

class Unionfind{
private:
    vector<int> nums;
public:
    Unionfind(int n){
        nums=vector<int>(n,0);
        for(int i=0;i<n;i++)
            nums[i]=i;
    }
    int rootfind(int i){
        if(i!=nums[i])
            nums[i]=rootfind(nums[i]);
        return nums[i];
    }
    void Union(int i,int j){
        int ri=rootfind(i),rj=rootfind(j);
        if(ri!=rj)
            nums[ri]=rj;
        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Unionfind u(n);
        map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(!m.count(accounts[i][j]))
                    m[accounts[i][j]]=i;
                else
                    u.Union(i,m[accounts[i][j]]);
            }
        }
        unordered_map<int,vector<string>> r_m;
        for(auto i:m) r_m[u.rootfind(i.second)].push_back(i.first);
        vector<vector<string>> res;
        for(int i=0;i<n;i++){
            if(r_m.count(i)){
                res.push_back({accounts[i][0]});
                for(auto j:r_m[i])
                    res[res.size()-1].push_back(j);
            }
        }
        return res;
    }
};

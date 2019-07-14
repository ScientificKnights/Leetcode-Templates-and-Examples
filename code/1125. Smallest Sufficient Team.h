/*
In a project, you have a list of required skills req_skills, and a list of people.  
The i-th person people[i] contains a list of skills that person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, 
there is at least one person in the team who has that skill.  We can represent these teams by the index of each person: 
for example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person.
You may return the answer in any order.  It is guaranteed an answer exists.

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 
Constraints:
1 <= req_skills.length <= 16
1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
Elements of req_skills and people[i] are (respectively) distinct.
req_skills[i][j], people[i][j][k] are lowercase English letters.
It is guaranteed a sufficient team exists.
*/

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(),m = people.size();
        unordered_map<string, int> needed;
        for(int i = 0; i < n; ++i) needed[req_skills[i]] = i;
        vector<vector<int>> dp(1 << n,vector<int>());

        for(int i = 0; i < m; ++i) {
            //find cur people
            int skill = 0;
            for(auto j : people[i]) {
                skill |= 1<< needed[j];
            }
            dp[skill]=vector<int>{i};
            
            for(int j = 0; j < (1 << n); ++j) {
                if(!dp[j].size()) continue;
                int new_skill = j | skill;
                if (!dp[new_skill].size() || dp[new_skill].size() > dp[j].size() + 1) {
                    dp[new_skill] = dp[j];
                    dp[new_skill].push_back(i);
                }
            }
        }
        return dp.back();
    }
};

/* unordered_map or map, need 300ms
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string,int> skill_map;
        for(int i=0;i< req_skills.size();i++)
            skill_map[req_skills[i]]=i;
        
        unordered_map<int,vector<int>> res;
        res[0]={};
        for(int i=0;i<people.size();i++)
        {
            int curr_skill = 0;
            for(int j=0;j<people[i].size();j++)
                curr_skill |= 1<<skill_map[people[i][j]];
            
            unordered_map<int,vector<int>> temp;
            for(auto j:res)
            {
                int comb = j.first | curr_skill;
                if(res.count(comb) && res[comb].size()>1+res[j.first].size())
                {
                    res[comb]=j.second;
                    res[comb].push_back(i);
                }
                else if(!res.count(comb)){
                    if(!temp.count(comb) || temp[comb].size()>1+res[j.first].size())
                    {
                        temp[comb]=j.second;
                        temp[comb].push_back(i);
                    }
                }
            }
            for(auto j:temp){
                res[j.first]=j.second;
            }
        }
        return res[(1<<n) -1];
    }
};
*/
/* backtrack 超时
class Solution {
private:
    void backtrack(unordered_map<int,int> &path,int pos,vector<vector<int>> &graph, int& res,unordered_map<int,int> &save){
        if(pos==graph.size()) {
            if(path.size()<res){
                res=path.size();
                save=path;
            }
            return;
        }
        for(int i=0;i<graph[pos].size();i++){
        
            path[graph[pos][i]]++;
            backtrack(path,pos+1,graph,res,save);
            path[graph[pos][i]]--;
            if(!path[graph[pos][i]])
                path.erase(graph[pos][i]);
        }
        return;
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size(),c=people.size();
        int res=c;
        unordered_map<string,int> m;
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
            m[req_skills[i]]=i;
        for(int i=0;i<c;i++){
            for(auto j:people[i])
                graph[m[j]].push_back(i);
        }
        unordered_map<int,int> path;
        unordered_map<int,int> save;
        for(int i=0;i<c;i++)
            save[i]=1;
        backtrack(path,0,graph,res,save);
        vector<int> result;
        for(auto i:save)
            result.push_back(i.first);
        return result;
    }
};
*/

/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. 
Thus, the itinerary must begin with JFK.

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. 
For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/

class Solution {
private:
    bool backtrack(unordered_map<string,map<string,int>> &graph,vector<string> &path, string s, int n){
        path.push_back(s);
        if(path.size()==n+1) return true;
        for(auto &i:graph[s]){
            if(i.second>0){
                i.second--;     //or add and backtrack in if block
                if(backtrack(graph,path,i.first,n)) 
                    return true;
                i.second++;
            }
        }
        path.pop_back();    //backtrack
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string,map<string,int>> graph;
        for(auto i:tickets){
            graph[i.first][i.second]++;
        }
        vector<string> res={};
        backtrack(graph,res,"JFK",tickets.size());
        return res;
    }
};

/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, 
and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

class UnionFind{
private:
    vector<pair<int,double>> root;
public:
    UnionFind(int n){
        root=vector<pair<int,double>> (n);
        for(int i=0;i<n;i++){
            root[i].first=i;
            root[i].second=1.0;
        }
    }
    pair<int,double> rootfind(int i){
        if(i!=root[i].first){
            auto cur=rootfind(root[i].first);
            root[i].first=cur.first;
            root[i].second*=cur.second;
        }
        return root[i];
    }
    void Union(int i,int j, double ratio){
        auto ri=rootfind(i),rj=rootfind(j);
        if(ri.first!=rj.first){
            root[ri.first].first=rj.first;
            root[ri.first].second=ratio*rj.second/ri.second;
        }
        return;
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int pos=0;
        unordered_map<string,int> m;    //dict string to pos
        for(auto i:equations){
            if(!m.count(i.first)){
                m[i.first]=pos++;
            }
            if(!m.count(i.second)){
                m[i.second]=pos++;
            }
        }
        UnionFind u(pos);
        for(int i=0;i<equations.size();i++)     //Union all equations
            u.Union(m[equations[i].first],m[equations[i].second],values[i]);
        
        vector<double> res(queries.size(),-1.0);
        for(int i=0;i<queries.size();i++){
            if(!m.count(queries[i].first) || !m.count(queries[i].second)) continue;     //input not found
            auto up=u.rootfind(m[queries[i].first]), down=u.rootfind(m[queries[i].second]);
            if(up.first!=down.first) continue;                                          //dont have the same root
            res[i]=up.second/down.second;
        }
        return res;
    }
};

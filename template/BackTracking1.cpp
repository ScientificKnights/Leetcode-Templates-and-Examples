/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Input: candidates = [2,3,5], target = 8,
A solution set is:
[  [2,2,2,2],  [2,3,3],  [3,5]  ]
*/

Sort(data.begin(),data.end())                          //sort后可以early stopping，sort复杂度远小于2^N
void helper(vector<vector> res, vector data, vector path, int target, int cur){ //可能有length
    if(target==0 找到的条件){	                         //如果找到了，返回
        res.push_back(path);
        return;
    }
    for(int i=cur;i<data.size() && 截止条件;i++){       //for loop 试从target开始的每个数字
		// combination sort I,II:data[i]<=target. III: target>=(i+i+length-1)*length/2
        path.push_back(data[i]);
        helper(res,data,path,target-data[i],i);        //可以重复i,不可重复i+1，有length限制，也-1
        path.pop_back();                               //backtracking!!
    }
    return;
}

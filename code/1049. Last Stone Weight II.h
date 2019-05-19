/*
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  
The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

Input: [2,7,4,1,8,1]
Output: 1
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //除了不能全正，其他都可能
        vector<bool> prev(6001,false);
        prev[3000]=true;
        for(auto i:stones){
            vector<bool> next(6001,false);
            for(int j=0;j<6001;j++){
                if(prev[j]){
                    next[j+i]=true;
                    next[j-i]=true;
                }
            }
            prev=next;
        }
        int res=3000;
        for(int i=0;i<6001;i++)
            if(prev[i])
                res=min(res, abs(i-3000));
        return res;
    }
};


/*
//backtrack OTL
class Solution {
public:
    bool backtrack(vector<int>& stones, int pos,int count,int path_sum,int &res,int len,int sum){
        if(pos==len ){//&& (count==len/2 || count==(len-len/2))){
            int temp=path_sum;
            res=min(res,abs(temp-sum+temp));
            return res==0;
        }
        //if(pos==len) return;
        if(backtrack(stones,pos+1,count,path_sum,res,len,sum))
            return true;
        //path_sum+=stones[pos];
        if(backtrack(stones,pos+1,count+1,path_sum+stones[pos],res,len,sum))
            return true;
        //path_sum-=stones[pos];
        return false;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0,n=stones.size();
        for(auto i:stones)
            sum+=i;
        int path_sum=0,res=INT_MAX;
        backtrack(stones,0,0,path_sum,res,n,sum);
        return res;
    }
};
*/

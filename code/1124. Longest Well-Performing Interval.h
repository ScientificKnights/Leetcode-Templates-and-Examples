/*
A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
A well-performing interval is an interval of days for which the number of tiring days is strictly larger than 
the number of non-tiring days.

Return the length of the longest well-performing interval.

Input: hours = [9,9,6,0,6,6,9]
Output: 3
*/

int longestWPI(vector<int>& hours) {
    // <=8 减1，>8 加一；
    // sum连续的；如果有小于当前sum，长度是那个sum的后一个index到cur
    //  -1 -1 -1 1  -1 -1  1  1
    //0 -1 -2 -3 -2 -3 -4 -3 -2
    unordered_map<int,int> seen;
    int n=hours.size(),sum=0,res=0;
    for(int i=0;i<n;i++){
        sum+= (hours[i]>8?1:-1);
        if(sum>0) res=i+1;  //大于0，第一个前面是0
        else{
            if(seen.count(sum-1))   //能找到小于sum的
                res=max(res,i-seen[sum-1]);
            if(!seen.count(sum))    //sum不在里面
                seen[sum]=i;
        }
    }
    return res;
}

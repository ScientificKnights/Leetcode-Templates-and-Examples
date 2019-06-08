/*
Given a collection of intervals, find the minimum number of intervals you need to remove 
to make the rest of the intervals non-overlapping.

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

Input: [ [1,2], [2,3], [3,4], [1,3] ]
Output: 1
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int i=0,j=1,res=0;
    while(j<intervals.size()){
        //if((intervals[i][0]-intervals[j][1])*(intervals[j][0]-intervals[i][1])>0){    //已经排序了，第一个肯定小
        if(intervals[j][0]<intervals[i][1]){
            if(intervals[j][1]<intervals[i][1]) i=j;
            j++;
            res++;
        }
        else{
            i=j;
            j++;
        }
    }
    return res;
}

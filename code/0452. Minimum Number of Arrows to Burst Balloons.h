/*
There are a number of spherical balloons spread in two-dimensional space. 
For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. 
Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. 
A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. 
The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2
*/
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end());
    int prev=INT_MIN,res=0;
    for(int i=0;i<points.size();i++){
        if( points[i][0]==INT_MIN || points[i][0]>prev){   //[INT_MIN, INT_MAX]
            prev=points[i][1];
            res++;
        }
        else if(points[i][1]<prev){
            prev=min(prev,points[i][1]);
        }
    }
    return res;
}

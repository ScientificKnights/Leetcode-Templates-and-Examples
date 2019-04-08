/*
You are given a series of video clips from a sporting event that lasted T seconds.  
These video clips can be overlapping with each other and have varied lengths.

Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  
We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  
If the task is impossible, return -1.

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
Output: 3
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
*/

int videoStitching(vector<vector<int>>& clips, int T) {
    sort(clips.begin(),clips.end());
    int start=0,end=0,res=0;
    for(int i=0;i<clips.size();i++){
        if(clips[i][0]>end)
            return -1;
        if(clips[i][0]>start){
            start=end;
            res++;
        }
        end=max(end,clips[i][1]);
        if(end>=T) return res+1;
    }
    return -1;
}

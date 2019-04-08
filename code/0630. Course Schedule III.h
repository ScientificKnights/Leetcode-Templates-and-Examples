/*
There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day.
A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.
Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

Example:

Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
 
The integer 1 <= d, t, n <= 10,000.
You can't take two courses simultaneously.
*/

int scheduleCourse(vector<vector<int>>& courses) {
    //greedy,按照close date 排序，选中的加入priority_queue
    //可以加，加入
    //不可以加入，尝试替换最长的
    //被替换的肯定无法在加入了 （长度长，截至短）
    sort(courses.begin(),courses.end(),[](vector<int> &a, vector<int> &b){return a[1]<b[1];});
    priority_queue<int> selected;
    int res=0;
    long long time=0;
    for(auto i:courses){
        if(time+i[0]<=i[1]){
            time+=i[0];
            selected.push(i[0]);
            res++;
        }
        else if(!selected.empty() && selected.top()>i[0]){
            time=time-selected.top()+i[0];
            selected.pop();
            selected.push(i[0]);
        }
    }
    return res;
}

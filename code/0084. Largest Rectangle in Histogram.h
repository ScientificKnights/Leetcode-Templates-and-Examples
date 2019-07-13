/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Input: [2,1,5,6,2,3]
Output: 10
*/

int largestRectangleArea(vector<int>& heights) {
    //类似与longest increasing
    int n=heights.size();
    if(n==0) return 0;
    stack<int> data;
    data.push(-1);data.push(0);
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(heights[i] > heights[data.top()])
            data.push(i);
        //要保证stack里前一个数是截至条件
        else if(heights[i]==heights[data.top()])
        {data.pop();  data.push(i);}
        else{
            while(data.size()>1 && heights[data.top()]>heights[i]){
                int m=data.top();
                data.pop();
                //从要插入的位置建都比他大
                res=max(res,(i-1-data.top())*heights[m]);
            }
            data.push(i);
        }
    }
    //还剩下
    while(data.size()>1){
        int m=data.top();
        data.pop();
        res=max(res,(n-1-data.top())*heights[m]);
    }
    return res;
}

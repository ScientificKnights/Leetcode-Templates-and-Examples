/*
We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , 
where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are 
the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane.  
Since the answer may be too large, return it modulo 10^9 + 7.
*/

int rectangleArea(vector<vector<int>>& rectangles) {
    set<int> x,y;
    for(auto i: rectangles){
        x.insert(i[0]),x.insert(i[2]),
        y.insert(i[1]),y.insert(i[3]);
    }
    vector<int> xx(x.begin(),x.end()),yy(y.begin(),y.end());
    int res=0;
    vector<vector<int>> data(xx.size()+1,vector<int>(yy.size()+1,0));
    for(auto i:rectangles)
        for(int j=lower_bound(xx.begin(),xx.end(),i[0])-xx.begin();xx[j]!=i[2];j++)
            for(int k=lower_bound(yy.begin(),yy.end(),i[1])-yy.begin();yy[k]!=i[3];k++)
                if((data[j][k]++)==0)
                    res=(res+((long long)(xx[j+1]-xx[j]))*(yy[k+1]-yy[k]))%1000000007;

    return res;
}

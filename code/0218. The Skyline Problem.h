/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance.
Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A),
write a program to output the skyline formed by these buildings collectively (Figure B).

Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, 
and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ]
that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, 
where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. 
Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:
The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline.
For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; 
the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //priority_queue [start, -heights] [end, heights]
        //prev [x, height]
        //multiset heights
        priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> data;
        for(auto i: buildings){
            // [1,2,5][2,3,5]    2,5关 要在 2，5开后面，开2，-5
            data.push({i[0],-i[2]});
            data.push({i[1],i[2]});
        }
        multiset<int> heights;
        heights.insert(0);  //删掉最后一个还能加入0
        vector<int> prev={0,0}; //make_pair(0,0);
        
        vector<vector<int>> res;
        while(!data.empty()){
            auto i=data.top();
            data.pop();
            //open
            if(i.second<0) heights.insert(-i.second);
            else heights.erase(heights.find(i.second));     //必须用find，要不会删除所有的相同的
            
            if(*heights.rbegin()!=prev[1]){
                prev[0]=i.first; prev[1]=*heights.rbegin();
                res.push_back(prev);
            }
        }
        return res;
    }
};
/*
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //multiset [start, heights] [end, - heights]
        //curr [x, height]
        //multiset heights
        multiset<pair<int, int>> data;
        for(auto i: buildings){
            // [1,2,5][2,3,5]    2,5关 要在 2，5开后面，开2，-5
            data.insert({i[0],-i[2]});
            data.insert({i[1],i[2]});
        }
        multiset<int> heights;
        heights.insert(0);  //删掉最后一个还能加入0
        vector<int> prev={0,0}; //make_pair(0,0);
        
        vector<vector<int>> res;
        for(auto i:data){
            //open
            if(i.second<0) heights.insert(-i.second);
            else heights.erase(heights.find(i.second));     //必须用find，要不会删除所有的相同的
            
            if(*heights.rbegin()!=prev[1]){
                prev[0]=i.first; prev[1]=*heights.rbegin();
                res.push_back(prev);
            }
        }
        return res;
    }
};
*/

/*
We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` 
and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. 
Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z

Note:
bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/

class Solution {
private:
    bool backtrack(vector<string> &path, int r, int c, unordered_set<string> &s) {
        if(r==-1) return true;
        for(int i=0;i<7;i++){
            string to_find(3,'A'+i);
            to_find[0]=path[r+1][c],to_find[1]=path[r+1][c+1];
            if(s.count(to_find)){
                path[r][c]='A'+i;
                if(r==c && backtrack(path,r-1,0,s)) return true;
                if(backtrack(path,r,c+1,s)) return true;
            }
        }
        return false;
    }
    
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string> s=unordered_set(allowed.begin(),allowed.end());
        int n=bottom.size();
        vector<string> path;
        for(int i=0;i<n-1;i++){
            path.push_back(string(i+1,' '));
        }
        path.emplace_back(bottom);
        return backtrack(path,n-2,0,s);
    }
};

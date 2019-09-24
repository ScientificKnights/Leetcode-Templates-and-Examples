/*
A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces 
in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. 
Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) 
that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).

Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)

Note:
A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.
*/

class RangeModule {
private:
    map<int,int> ranges;
public:
    RangeModule() {
    }
    //O(k+logN) , k overlap number
    void addRange(int left, int right) {
        auto l=ranges.upper_bound(left),r=ranges.upper_bound(right);
        if(l!=ranges.begin()){
            l--;
            if(l->second>=left){
                left=min(left,l->first);
            }
            else{
                l++;
            }
        }
        if(r!=ranges.begin()){
            r--;
            right=max(right,r->second);
            r++;
        }
        ranges.erase(l,r);
        ranges[left]=right;
    }
    //O(logN)
    bool queryRange(int left, int right) {
        auto iter=ranges.upper_bound(left);     //大于，--iter first等于或者小于
        if(iter==ranges.begin()||(--iter)->second<right) return false;
        return true;
    }
    //O(k+logN) , k overlap number
    void removeRange(int left, int right) {
        auto l=ranges.upper_bound(left),r=ranges.upper_bound(right);
        int l_temp=left,r_temp=right;
        if(l!=ranges.begin()){
            l--;
            if(l->second>left){
                l_temp=min(left,l->first);
            }
            else{
                l++;
            }
        }
        if(r!=ranges.begin()){
            r--;
            r_temp=max(right,r->second);
            r++;
        }
        ranges.erase(l, r);
        if (l_temp < left) 
            ranges[l_temp] = left;
        if (r_temp > right) 
            ranges[right] = r_temp;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

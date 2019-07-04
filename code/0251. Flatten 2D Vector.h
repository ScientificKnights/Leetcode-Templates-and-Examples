/*
Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false
 
Notes:
Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted 
across multiple test cases. Please see here for more details.
You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector 
when next() is called. 
*/
class Vector2D {
private:
    vector<vector<int>>::iterator s,e;
    int j;
public:
    //考虑，开头，结尾，中间是空vector
    Vector2D(vector<vector<int>>& v) {
        s=v.begin(),e=v.end();
        while(s!=e && (*s).size()==0) s++; // [[][]]
        j=0;
    }
    
    int next() {
        int res=(*s)[j++];
        while(s!=e && j==(*s).size()){
            s++;j=0;
        }
        return res;
    }
    
    bool hasNext() {
        return s!=e;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose the two heaviest rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  
The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
*/

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> q;
    for(auto i:stones) q.push(i);
    while(q.size()>1){
        int i=q.top();
        q.pop();
        int j=q.top();
        q.pop();
        if(i!=j) q.push(abs(i-j));
    }
    return (q.size())?q.top():0;
}

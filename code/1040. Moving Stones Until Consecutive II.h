/*
On an infinite number line, the position of the i-th stone is given by stones[i].  
Call a stone an endpoint stone if it has the smallest or largest position.

Each turn, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, 
since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.

The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.
When the game ends, what is the minimum and maximum number of moves that you could have made?  
Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]

Input: [7,4,9]
Output: [1,2]
Explanation: 
We can move 4 -> 8 for one move to finish the game.
Or, we can move 9 -> 5, 4 -> 6 for two moves to finish the game.

Input: [6,5,4,3,10]
Output: [2,3]
We can move 3 -> 8 then 10 -> 7 to finish the game.
Or, we can move 3 -> 7, 4 -> 8, 5 -> 9 to finish the game.
Notice we cannot move 10 -> 2 to finish the game, because that would be an illegal move.
*/

vector<int> numMovesStonesII(vector<int>& stones) {
    //max情况：最边上的吧里面的所有位置都经历一编
    //min，长度为n的最大cover多少。n-1个连续是特殊情况，无法直接移动边上的。
    sort(stones.begin(),stones.end());
    int n=stones.size(),low=INT_MAX,j=0;
    //if(stones[n-1]-stones[0]==n-1) return {0,0};
    for(int i=0;i<n;i++){
        while(stones[i]-stones[j]>n-1) j++;
        if(i-j==n-2 && stones[i]-stones[j]==n-2)            //1238->low不是1
            low=min(low,2);
        else
            low=min(low,n-(i-j+1));                         //1235->low是1，12345
    }
    return {low, max(stones[n-2]-stones[0]+1-(n-1),stones[n-1]-stones[1]+1-(n-1))};
}

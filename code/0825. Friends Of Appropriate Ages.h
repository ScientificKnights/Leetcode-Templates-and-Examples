/*
Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 
Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.
How many total friend requests are made?

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.

Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.

Input: [20,30,100,110,120]
Output: 
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 
Notes:
1 <= ages.length <= 20000.
1 <= ages[i] <= 120.
*/

int numFriendRequests(vector<int>& ages) {
    //没有必要sort or map，年龄数字小
    vector<int> count(121,0);
    int res=0;
    for(auto i:ages)
        count[i]++;
    // 向小于等于自己年龄的发request, sliding sum
    for(int i=1;i<=120;i++){
        for(int j=0.5*i+8;j<=i;j++){
            if(i==j) res+=count[i]*(count[i]-1);
            else res+=count[j]*count[i];
        }
    }
    return res;
}

/*
In an election, the i-th vote was cast for persons[i] at time times[i].

Now, we would like to implement the following query function: 
TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.  

Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.

Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Note:

1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times is a strictly increasing array with all elements in [0, 10^9].
TopVotedCandidate.q is called at most 10000 times per test case.
TopVotedCandidate.q(int t) is always called with t >= times[0].
*/
class TopVotedCandidate {
private:
    map<int,int> count;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int,int> m;
        int ma=0,ma_person,n=persons.size();
        for(int i=0;i<n;i++){
            if(++m[persons[i]]>=ma){
                ma=m[persons[i]];
                ma_person=persons[i];
            }
            count[times[i]]=ma_person;
        }
    }
    
    int q(int t) {
        auto ii=count.upper_bound(t);
        return prev(ii)->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

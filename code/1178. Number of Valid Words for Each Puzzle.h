/*
With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; 
while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words that are valid
with respect to the puzzle puzzles[i].

Input:
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation:
1 valid word for "aboveyz" : "aaaa" 
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There're no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
 
Constraints:
1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] are English lowercase letters.
Each puzzles[i] doesn't contain repeated characters.
*/

class Tire{
private:
    int count=0;
public:
    unordered_map<char,Tire*> m;
    void insert(const set<char> &word){
        Tire* cur=this;
        for(auto i:word){
            if(cur->m.count(i)==0)
                cur->m[i]=new Tire();
            cur=cur->m[i];
        }
        cur->count++;
    }
    int getCount(){
        return count;
    }
};

class Solution {
private:
    void search(Tire* t, const vector<int> &dict, int &res, char firstChar, bool foundFirst){
        if(t->getCount() && foundFirst) res+=t->getCount();
        for(auto i: t->m){
            if(dict[i.first-'a']>0){
                search(i.second,dict,res,firstChar,foundFirst||(i.first==firstChar));
            }
        }
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        Tire* t=new Tire();
        // string 变成 set 压缩内存
        for(auto i:words){
            set<char> s(i.begin(),i.end());
            t->insert(s);
        }
        vector<int> res;

        for(auto i: puzzles){
            int count=0;
            vector<int> a(26,0);    //如果用set会变慢 700ms, 可能是search里面index快
            for(auto j:i)
                a[j-'a']++;
            search(t, a, count, i[0], false);
            res.push_back(count);
        }
        return res;
    }
};

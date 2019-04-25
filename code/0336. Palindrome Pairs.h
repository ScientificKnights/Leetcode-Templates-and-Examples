/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
*/

class Tire{
private:
    Tire* next[26];
    int end=-1;
    vector<int> index;
public:
    Tire(){
        for(auto &i:next) i=NULL;
    }
    ~Tire(){
        for(auto &i:next)
            if(i)
                delete i;
    }
    bool ispalindrome(string& word, int i, int j){
        //whether palindrome from index i to index j
        while(i<j){
            if(word[i++]!=word[j--]) return false;
        }
        return true;
    }
    void add(string &s,int num){
        Tire *cur=this;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!cur->next[s[i]-'a'])
                cur->next[s[i]-'a']=new Tire();
            cur->index.push_back(num);
            cur=cur->next[s[i]-'a'];
        }
        cur->end=num;
        return;
    }
    void search(vector<string>& words, int i_reverse, vector<vector<int>> &res){
        Tire *cur=this;
        string s=words[i_reverse];
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(cur->end!=-1){
                if(ispalindrome(s,0,n-words[cur->end].size()-1))
                    res.push_back({cur->end,i_reverse});
            }
            if(!cur->next[s[i]-'a']) return;
            else cur=cur->next[s[i]-'a'];
        }
        //漏掉了 tire正好在这结束
        if(cur->end!=-1 && cur->end!=i_reverse) 
            res.push_back({cur->end, i_reverse});
        
        if(cur->index.size()){
            for(auto i: cur->index){
                if(ispalindrome(words[i],n,words[i].size()-1))
                    res.push_back({i,i_reverse});
            }
        }
        return;
    }
};

class Solution {
private:
    Tire* root=new Tire();
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for(int i=0;i<words.size();i++)
            root->add(words[i],i);
        vector<vector<int>> res;
        for(int i=0;i<words.size();i++)
            root->search(words,i,res);
        return res;
    }
};

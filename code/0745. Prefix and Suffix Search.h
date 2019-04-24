/*
Given many words, words[i] has weight i.
Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). 
It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1

words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.
*/

class Node{
private:
    Node* next[26];
    vector<int> weights={};
public:
    Node(){
        for(auto &i:next) i=NULL;
    }
    
    void add(string &s,int begin,int step,int index){
        int n=s.size();
        Node *cur=this;
        cur->weights.push_back(index);  //empty has every index
        for(int i=begin;i<n&&i>=0;i+=step){
            if(!cur->next[s[i]-'a'])
                cur->next[s[i]-'a']=new Node();
            cur=cur->next[s[i]-'a'];
            cur->weights.push_back(index);
        }
        return;
    }
    vector<int> search(string &s,int begin,int step){
        int n=s.size();
        Node*cur=this;
        for(int i=begin;i<n&&i>=0;i+=step){
            if(!cur->next[s[i]-'a'])
                return {};
            else
                cur=cur->next[s[i]-'a'];
        }
        return cur->weights;
    }
    
    ~Node(){
        for(int i=0;i<26;i++)
            if(next[i])
                delete next[i];
    }
};

int overlap(const vector<int> &a,const vector<int> &b){
    int i=a.size()-1,j=b.size()-1;
    while(i>=0 && j>=0){
        if(a[i]==b[j])
            return a[i];
        else if(a[i]>b[j]) i--;
        else j--;
    }
    return -1;
}
class WordFilter {
private:
    Node* suffix;
    Node* prefix;
public:
    WordFilter(vector<string>& words) {
        suffix=new Node();
        prefix=new Node();
        int n=words.size();
        for(int i=0;i<n;i++){
            prefix->add(words[i],0,1,i);
            suffix->add(words[i],words[i].size()-1,-1,i);
        }
    }
    
    int f(string pre, string suf) {
        vector<int> a=prefix->search(pre,0,1);
        vector<int> b=suffix->search(suf,suf.size()-1,-1);
        return overlap(a,b);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

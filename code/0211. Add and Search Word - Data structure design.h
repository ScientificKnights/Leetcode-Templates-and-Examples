/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .
. means it can represent any one letter.

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

class Tire{
private:
    bool isend=false;
    unordered_map<char,Tire*> m;
public:
    void insert(string word){
        Tire* cur=this;
        for(auto i:word){
            if(!cur->m.count(i))
                cur->m[i]=new Tire();
            cur=cur->m[i];
        }
        cur->isend=true;
    }
    
    bool search(int pos, const string & word){
        Tire* cur=this;
        if(cur->m.count(word[pos])){
            cur=cur->m[word[pos]];
            if(pos==word.size()-1) return cur->isend;
            return cur->search(pos+1,word);
        }
        if(word[pos]=='.'){
            for(auto i:cur->m){
                if(pos==word.size()-1 && i.second->isend) return true;
                if(i.second->search(pos+1,word))   return true;
            }
            return false;
        }
        return false;
    }
};
class WordDictionary {
private:
    Tire* t;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        t=new Tire();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        t->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return t->search(0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

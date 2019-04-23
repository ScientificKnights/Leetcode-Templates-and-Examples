/*
Implement a trie with insert, search, and startsWith methods.

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

class Node{
private:
    Node* nexts[26];
    bool end=false;
public:    
    Node(){
        for(auto &i:nexts)
            i = NULL;
    }
    void insert(string &s{
        Node* cur=this;
        int n=s.size();
        for(int i = 0; i < n; i ++)
        {
            if (! cur -> nexts[s[i] - 'a'])
                cur -> nexts[s[i] - 'a'] = new Node();
            cur = cur -> nexts[s[i] - 'a'];
        }
        cur -> end = true;
        return;
    }
    bool search(string &s){
        Node* cur=this;
        int n=s.size();
        for(int i = 0; i < n; i ++)
        {
            if (! cur -> nexts[s[i] - 'a'])
                return false;
            cur = cur -> nexts[s[i] - 'a'];
        }
        return cur -> end;
    }
    
    bool startsWith(string &prefix){
        Node* cur=this;
        int n=prefix.size();
        for(int i = 0; i < n; i ++)
        {
            if (! cur -> nexts[prefix[i] - 'a'])
                return false;
            cur = cur -> nexts[prefix[i] - 'a'];
        }
        return true;
    }
};

class Trie {
public:
    Node* head;
    /** Initialize your data structure here. */
    Trie() {
        head = new Node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        head -> insert(word);
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return head -> search(word);
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return head -> startsWith(prefix);
    }
};

/*
Implement the StreamChecker class as follows:
StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried 
(in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
*/

class Node{
private:
    bool end=false;
    Node *next[26];
public:
    Node(){
        for(auto &i:next)
            i=NULL;
    }
    void insert(string &s){
        Node * cur=this;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(!cur->next[s[i]-'a'])
                cur->next[s[i]-'a']=new Node();
            cur=cur->next[s[i]-'a'];
        }
        cur->end=true;
    }
    bool search(string &query){
        Node * cur=this;
        int n=query.size();
        for(int i=n-1;i>=0;i--){
            if(cur->end) return true;
            if(!cur->next[query[i]-'a'])
                return false;
            cur=cur->next[query[i]-'a'];
        }
        return cur->end;        //最后一个
    }
};
class StreamChecker {
private:
    Node* root;
    string s="";
public:
    StreamChecker(vector<string>& words) {
        root=new Node();
        for(auto i:words) root->insert(i);
    }
    
    bool query(char letter) {
        s+=letter;
        return root->search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

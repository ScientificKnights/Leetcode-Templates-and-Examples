/*
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, 
determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, 
if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].
Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, 
then "great" and "fine" are similar.
Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.
Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, 
even though there are no specified similar word pairs.
Finally, sentences can only be similar if they have the same number of words. 
*/
    int findroot(vector<int>& root, int pos){
        while(root[pos]!=pos){
            pos=root[pos];
        }
        return pos;
    }
    
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int n=words1.size();
        int m=words2.size();
        if(n!=m)
            return false;
        unordered_map<string,int> data;   //word to int for rootfind
        vector<int> root;
        
        for(auto ii:pairs){     //build rootfind with dict
            auto p1=data.find(ii.first);
            auto p2=data.find(ii.second);
            int len=root.size();
            
            if(p1==data.end()){
                root.push_back(len);
                data[ii.first]=len++;
            }
            if(p2==data.end()){
                root.push_back(len);
                data[ii.second]=len;
            }
            root[findroot(root,data[ii.first])]=findroot(root,data[ii.second]);
        }
        
        for(int i=0;i<n;i++){   //find whether every word has the same root
            if(words1[i]==words2[i])
                continue;
            if(data.find(words1[i])==data.end() || data.find(words2[i])==data.end())
                return false;
            if(findroot(root,data[words1[i]])!=findroot(root,data[words2[i]]))
                return false;
        }
        return true;
    }

/*
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once 
and without any intervening characters.

  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]

  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/

vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> m,m_s;
    if(!words.size()) return vector<int>();

    for(auto i:words)
        m[i]++;

    int n=s.size(),k=words[0].size();
    vector<int> res;

    for(int l=0;l<k;l++){
        int start=l;
        m_s=unordered_map<string,int>();
        for(int i=l;i<n;i+=k){
            string cur=s.substr(i,k);
            if(m.count(cur)){
                m_s[cur]++;
                if(m_s==m) {
                    res.push_back(start);
                }
                else if(m_s[cur]>m[cur]) {
                    for(int j=start;j<i;j+=k){
                        string temp=s.substr(j,k);
                        m_s[temp]--;
                        if(temp==cur){
                            start=j+k;
                            if(m_s==m) res.push_back(start);
                            break;
                        }
                    }
                }
            }
            else{
                m_s=unordered_map<string, int>();
                start=i+k;
            }
        }
    }
    return res;
}

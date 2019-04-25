/*
Given a list of strings words representing an English Dictionary, 
find the longest word in words that can be built one character at a time by other words in words. 
If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

words = ["w","wo","wor","worl", "world"]
Output: "world"

["m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"]
"latte"
*/

string longestWord(vector<string>& words) {
    sort(words.begin(),words.end());
    unordered_set<string> s;
    s.insert("");
    string res="";
    for(int i=0;i<words.size();i++)
        if(s.count(words[i].substr(0,words[i].size()-1))){
            s.insert(words[i]);
            if(words[i].size()>res.size())
                res=words[i];
        }
    return res;
}

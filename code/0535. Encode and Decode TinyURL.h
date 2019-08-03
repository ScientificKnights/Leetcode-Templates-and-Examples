/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl 
and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution {
private:
    unordered_map<string,string> lTos,sTol;
    string s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(lTos.count(longUrl)) return lTos[longUrl];
        string shortUrl="";
        while(shortUrl==""){
            // collision
            string res;
            for(int i=0;i<6;i++){
                res+=rand()%s.size();
            }
            if(!sTol.count(res)){
                lTos[longUrl]=res;
                sTol[res]=longUrl;
                shortUrl=res;
            }
        }
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //假设一定有
        return sTol[shortUrl];
    }
};

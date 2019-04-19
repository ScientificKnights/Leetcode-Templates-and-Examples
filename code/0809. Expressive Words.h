/*
Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii". 
In these strings like "heeellooo", we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".

For some given string S, a query word is stretchy if it can be made to be equal to S by any number of applications 
of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group 
so that the size of the group is 3 or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", 
but we cannot get "helloo" since the group "oo" has size less than 3.  Also, we could do another extension like "ll" -> "lllll" 
to get "helllllooo".  If S = "helllllooo", then the query word "hello" would be stretchy 
because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.

Given a list of query words, return the number of words that are stretchy. 
 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
*/

int expressiveWords(string S, vector<string>& words) {
    int res=0;
    for(auto word: words){
        int n=S.size(),m=word.size(),start1=0,start2=0,end1=0,end2=0;
        while(start1<n && start2<m){
            if(S[start1]==word[start2]){
                end1=start1+1,end2=start2+1;
                while(end1<n && S[end1]==S[start1])
                    end1++;
                while(end2<n && word[end2]==word[start2])
                    end2++;
                if((end1-start1)<(end2-start2) || ((end1-start1)>(end2-start2) && (end1-start1)<3))
                    break;
                start1=end1,start2=end2;
            }
            else{
                break;
            }
        }
        if((start1==n&&start2==m)) res++;
    }
    return res;
}

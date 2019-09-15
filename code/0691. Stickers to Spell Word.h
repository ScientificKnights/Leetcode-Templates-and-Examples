/*
We are given N different types of stickers. Each sticker has a lowercase English word on it.
You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.
You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.

Input:
["with", "example", "science"], "thehat"
Output:
3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.


Input:
["notice", "possible"], "basicbasic"
Output:
-1
Explanation:
We can't form the target "basicbasic" from cutting letters from the given stickers.

Note:
stickers has length in the range [1, 50].
stickers consists of lowercase English words (without apostrophes).
target has length in the range [1, 15], and consists of lowercase English letters.
In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.
*/

int minStickers(vector<string>& stickers, string target) {
    //O(T)=1<<n * M(sticker所有字母) *n
    int n=target.size();
    //从0开始扫，因为没用temp，可以重复出现
    vector<int> dp(1<<n,-1);
    dp[0]=0;
    for(int i=0;i<(1<<n);i++){
        if(dp[i]==-1) continue;
        cout<<i<<endl;
        for(auto j:stickers){
            int next=i;
            for(auto c:j){
                for(int k=0;k<n;k++){
                    if(((next>>k)&1)==1) continue;  //检查target是否在这位有东西了
                    if(target[k]==c){
                        next|=1<<k;
                        break;  //停止，不然相同的字母会加到后面
                    }
                }
            }
            if((dp[next]==-1 || dp[next]>(dp[i]+1))){ //新的用了这个sticker的位置
                dp[next]=dp[i]+1;
            }
        }
    }
    return dp.back();
}

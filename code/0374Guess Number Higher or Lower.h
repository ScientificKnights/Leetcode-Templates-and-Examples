/*
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.
You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
 */
 
 int guessNumber(int n) {
    int start=1,end=n;
    while(start<=end){  //n+1会OVERFLOW，所以[l,r]用等号，不是[l,r) 
        int mid=start+(end-start)/2;
        int res=guess(mid);
        if(res==0)
            return mid;
        else if(res==-1)
            end=mid-1;  //mid and mid-1 both OK
        else
            start=mid+1;
    }
    return -1;
}

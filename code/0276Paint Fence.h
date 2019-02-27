/*
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
*/

int numWays(int n, int k) {
    //no three are same
    //multiple two same are ok.
    //DP, two states：same as last, different from last. states add one more degree: 1D to 2D
    //memory 2D 压缩为 1D
    
    if(n<1||k<1)
        return 0;
    if(n==1)
        return k;
    else if(n==2)
        return k*k;
    else{
        //same as last one
        int same=k;
        int diff=k*(k-1);
        for(int i=2;i<n;i++){
            //存same。新same就是diff+最后颜色，保证不会三联。
            //新diff，是之前所以的+新色
            int last_same=same;
            same=diff;
            diff=(last_same+diff)*(k-1);
        }
        return same+diff;
    }
}

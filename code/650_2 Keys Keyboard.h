/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. 
Output the minimum number of steps to get n 'A'.
*/

int minSteps(int n) {
    //必须能整除
    //3 1 1 1
    //4 2*2
    //5 1 1 1 1 1
    //6 3*2
    //8 2*2*2
    //10 2*5 2+5 or 5*2 5+2
    int ans=0;
    while(n!=1){
        for(int i=2;i<=n;i++){
            if(n%i==0){
                ans+=i;
                n/=i;
                break;
            }
        }
    }
    return ans;
}

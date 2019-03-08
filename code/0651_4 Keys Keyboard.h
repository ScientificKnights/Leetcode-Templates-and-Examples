/*
Imagine you have a special keyboard with the following keys:
Key 1: (A): Print one 'A' on screen.
Key 2: (Ctrl-A): Select the whole screen.
Key 3: (Ctrl-C): Copy selection to buffer.
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
Now, you can only press the keyboard for N times (with the above four keys), 
find out the maximum numbers of 'A' you can print on screen.
*/

int maxA(int N) {
    // make copied number also large
    //1 print
    //2 print print
    //3 print print print
    //4 all print
    //5 all print
    //6 print print print select copy paste 6(3)
    //7 3 print                             9(3)
    //8 4 print                             12(4) or(3)
    //9 4 print                             16(4)
    //10 5                                  20(5)
    //11                                    27(9)
    //12                                    36(12)
    //13                                    48(16)
    //14                                    64(16)

    //最多paste五次, 只用比较前面最多五次paste结果哪个大
    //如果6次paste(7X), 更好的办法是 paste 3+sel+copy+paste(8X)
    //如果7次paste(8X)，更好的办法是 paste 3+sel+copy+paste 2(12X)
    
    if(N<=6) return N;
    vector<int> data(N+1,0);
    for(int i=1;i<7;i++)
        data[i]=i;
        
    for(int i=7;i<N+1;i++){
        for(int j=1;j<=5;j++){
            data[i]=max(data[i],data[i-j-2]*(j+1));
        }
    }        
    return data[N];
}

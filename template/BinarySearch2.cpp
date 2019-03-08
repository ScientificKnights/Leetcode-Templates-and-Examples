//Implement int sqrt(int x).

int left=1, right=x,mid;
while(left<right){
    mid=left+(right-left)/2;
    if(mid>x/mid)		//先判断右侧是否满足，update r, 少用乘法，防止越界；
        right=mid;
    else
        left=mid+1;		
}
return start-1;		//因为一定能找到，所以while loop外返回，start-1是没发生相变最大的，start是发生相变后第一个

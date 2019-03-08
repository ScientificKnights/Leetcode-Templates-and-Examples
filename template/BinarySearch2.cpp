//Implement int sqrt(int x).

int left=1, right=x,mid;
while(left<right){  
    mid=left+(right-left)/2;
    //先判断右侧是否满足，update r, 少用乘法，防止越界；
    //如果mid>(). 找到的left>target; left-1<=target; return left-1
    //如果mid>=(). 找到的left>=target; left-1<target; return left
    if(mid>x/mid)
        right=mid;
    else
        left=mid+1;	
}
return left-1;		//因为一定能找到，所以while loop外返回，left-1是没发生相变最大的，left是相变发生后的

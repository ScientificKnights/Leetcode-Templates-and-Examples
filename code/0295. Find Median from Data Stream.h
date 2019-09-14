/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:
If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/

class MedianFinder {
    //Method ONE: two priority queue
    //Method TWO: multiset
    
    // multiset: 不能用set可以相等
    //不能指针加index，O(n)
private:
    multiset<int> data;
    multiset<int>::iterator mid;
public:
    /** initialize your data structure here. */
    MedianFinder() {       
    }
    void addNum(int num) {
        if(data.size()==0){
            data.insert(num);
            mid=data.begin();
            return;
        }
        //如果相等会upper_bound
        //加到后面
        //next and prev 不移动，返回指针，赋值移动
        data.insert(num);
        if(num>=*mid &&data.size()%2==1){
            mid=next(mid);
        }
        else if(num<*mid &&data.size()%2==0){
            mid=prev(mid);
        }
    }
    double findMedian() {
        int n=data.size();
        return 1.0*(*mid+*next(mid, 1-n%2))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

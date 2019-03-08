# Leetcode
## 1. Dynamic Programming
When to use: 之后的结果对前面没有影响，并且存在关系 F(n)=f(F(k<n)). 解决dp问题关键是找到推进公式  
问题格式： HOW MANY?? MAXMUM/MINMUM?? TURE/FALSE??  
### a) 1D, 找到公式后得到下一个
i) 公式只用前面一个element: [counting bits](https://github.com/chbyang/Leetcode/blob/master/code/0338Counting%20Bits.h)  
ii) 公式用前面几个elements: [House Robber](https://github.com/chbyang/Leetcode/blob/master/code/0198House%20Robber.h) (Similar: [House Robber II](https://github.com/chbyang/Leetcode/blob/master/code/0213House%20Robber%20II.h))/ [4 Keys Keyboard](https://github.com/chbyang/Leetcode/blob/master/code/0651_4%20Keys%20Keyboard.h)   
iii) 公式用前面所有elements: [Unique Binary Search](https://github.com/chbyang/Leetcode/blob/master/code/0096Unique%20Binary%20Search%20Trees.h)  / [Perfect Squares](https://github.com/chbyang/Leetcode/blob/master/code/0279Perfect%20Squares.h) / [2 Keys Keyboard](https://github.com/chbyang/Leetcode/blob/master/code/0650_2%20Keys%20Keyboard.h)  
### b) 2D
[Template](https://github.com/chbyang/Leetcode/blob/master/template/2D_DP1.cpp)  
小技巧，通常内存可以2D压缩为1D，如果公式是k[i][j]=k[i-1][j-1]+k[i-1][j]。可以直接存一个vector，计算时从最后算，避免覆盖  
i) 公式递进： 
[Edit Distance](https://github.com/chbyang/Leetcode/blob/master/code/0072Edit%20Distance.h) (Similar: [Minimum ASCII Delete Sum for Two Strings](https://github.com/chbyang/Leetcode/blob/master/code/0712Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings.h) / [Delete Operation for Two Strings](https://github.com/chbyang/Leetcode/blob/master/code/0583Delete%20Operation%20for%20Two%20Strings.h) / [Longest Palindromic Subsequence](https://github.com/chbyang/Leetcode/blob/master/code/0516Longest%20Palindromic%20Subsequence.h) / [Maximum Length of Repeated Subarray](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0718Maximum%20Length%20of%20Repeated%20Subarray.h) / [Regular expression](https://github.com/chbyang/Leetcode/edit/master/code/0010Regular%20Expression%20Matching.h) / [Wildcard matching](https://github.com/chbyang/Leetcode/blob/master/code/0044Wildcard%20Matching.h)) / [Dungeon Game](https://github.com/chbyang/Leetcode/blob/master/code/0174Dungeon%20Game.h) / [Paint House](https://github.com/chbyang/Leetcode/blob/master/code/0256Paint%20House.h) (Similar: [Paint House II](https://github.com/chbyang/Leetcode/blob/master/code/0265Paint%20House%20II.h)) / []/()  
ii) 1D扩为2D, state是新的degree, 内存可2D压缩为1D：[Paint Fence](https://github.com/chbyang/Leetcode/blob/master/code/0276Paint%20Fence.h) / [Minimum Swaps To Make Sequences Increasing](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0801Minimum%20Swaps%20To%20Make%20Sequences%20Increasing.h) / [Best Time to Buy and Sell Stock III]() (Similar: [Best Time to Buy and Sell Stock IV]())  
iii) 对角线推进: [Burst Bolloons](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0312Burst%20Balloons.h)  
## 2. Binary Search
i) 不一定找到：[Template 1](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BinarySearch1.cpp)  
[Binary Search](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0704Binary%20Search.h) / [Guess Number Higher or Lower](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0374Guess%20Number%20Higher%20or%20Lower.h)  
ii) 一定找到：[Template 2](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BinarySearch2.cpp)  
a) mid>() return left-1 [Sqrt](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0069Sqrt(x).h) / []()  
b) mid>=() return left []() /()[]
## 3. DFS

## 4. BFS

## 5. Backtracking

## 6. Union Find

## 7. Sliding Window
[Template](https://github.com/chbyang/Leetcode/blob/master/template/SlidingWindow1.cpp)
### key,count
### key,position
[Longest Substring Without Repeating Characters](https://github.com/chbyang/Leetcode/blob/master/code/0003LongestSubstrWithoutRepeatingCharacters.h)  

## 8. Two Pointers

## 9. Tree

## 10. Stack


## unordered_map
[TWO SUM](https://github.com/chbyang/Leetcode/blob/master/code/0001TwoSum.h) 

## linked list
[AddTwoNumbers](https://github.com/chbyang/Leetcode/blob/master/code/0002AddTwoNumbers.h)

## sum
[TWO SUM](https://github.com/chbyang/Leetcode/blob/master/code/0001TwoSum.h) 

# Leetcode
## 1. Dynamic Programming
When to use: 之后的结果对前面没有影响，并且存在关系 F(n)=f(F(k<n)). 解决dp问题关键是找到推进公式  
问题格式： HOW MANY?? MAXMUM/MINMUM?? TURE/FALSE?? Longest/Largest??  
### a) 1D, 找到公式后得到下一个
i) 公式只用前面一个element: [counting bits](https://github.com/chbyang/Leetcode/blob/master/code/0338Counting%20Bits.h)  
ii) 公式用前面几个elements: [House Robber I](https://github.com/chbyang/Leetcode/blob/master/code/0198House%20Robber.h), [II](https://github.com/chbyang/Leetcode/blob/master/code/0213House%20Robber%20II.h) (Similar: [Delete and Earn](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0740.%20Delete%20and%20Earn.h)) / [4 Keys Keyboard](https://github.com/chbyang/Leetcode/blob/master/code/0651_4%20Keys%20Keyboard.h) (Similar: [Integer Break](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0343.%20Integer%20Break.h))  
iii) 公式用前面所有elements: [Unique Binary Search](https://github.com/chbyang/Leetcode/blob/master/code/0096Unique%20Binary%20Search%20Trees.h)  / [Perfect Squares](https://github.com/chbyang/Leetcode/blob/master/code/0279Perfect%20Squares.h) / [2 Keys Keyboard](https://github.com/chbyang/Leetcode/blob/master/code/0650_2%20Keys%20Keyboard.h)  
### b) 2D
[Template](https://github.com/chbyang/Leetcode/blob/master/template/2D_DP1.cpp)  
小技巧，通常内存可以2D压缩为1D，如果公式是k[i][j]=k[i-1][j-1]+k[i-1][j]。可以直接存一个vector，计算时从最后算，避免覆盖  
i) 公式递进： [Edit Distance](https://github.com/chbyang/Leetcode/blob/master/code/0072Edit%20Distance.h) (Similar: [Minimum ASCII Delete Sum for Two Strings](https://github.com/chbyang/Leetcode/blob/master/code/0712Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings.h) / [Delete Operation for Two Strings](https://github.com/chbyang/Leetcode/blob/master/code/0583Delete%20Operation%20for%20Two%20Strings.h) / [Regular expression](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0010.%20Regular%20Expression%20Matching.h) / [Wildcard matching](https://github.com/chbyang/Leetcode/blob/master/code/0044Wildcard%20Matching.h)) / [Dungeon Game](https://github.com/chbyang/Leetcode/blob/master/code/0174Dungeon%20Game.h) / [Paint House I](https://github.com/chbyang/Leetcode/blob/master/code/0256Paint%20House.h), [II](https://github.com/chbyang/Leetcode/blob/master/code/0265Paint%20House%20II.h) / [Bomb Enemy](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0361.%20Bomb%20Enemy.h) / [Longest Palindromic Subsequence](https://github.com/chbyang/Leetcode/blob/master/code/0516Longest%20Palindromic%20Subsequence.h) (Similar: [Maximum Length of Repeated Subarray](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0718Maximum%20Length%20of%20Repeated%20Subarray.h) / [Largest Divisible Subset](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0368.%20Largest%20Divisible%20Subset.h))  
ii) 1D扩为2D, state是新的degree, 内存可2D压缩为1D：[Paint Fence](https://github.com/chbyang/Leetcode/blob/master/code/0276Paint%20Fence.h) / [Minimum Swaps To Make Sequences Increasing](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0801Minimum%20Swaps%20To%20Make%20Sequences%20Increasing.h) / [Domino and Trimino Tiling](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0790.%20Domino%20and%20Tromino%20Tiling.h) / [Odd Even Jump](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0975.%20Odd%20Even%20Jump.h) / [Best Time to Buy and Sell Stock III](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III.h), [IV](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0188.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20IV.h), [with Cooldown](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0309.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown.h)  
iii) 对角线推进: [Burst Bolloons](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0312Burst%20Balloons.h) / [Stone Game](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0877.%20Stone%20Game.h) / [Palindrome Partitioning](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0132.%20Palindrome%20Partitioning%20II.h)  
### c) Memoizatoin: Top Down
[Race Car](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0818.%20Race%20Car.h)  
## 2. Binary Search
### a) 不一定找到：
[Template 1](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BinarySearch1.cpp)  
[Binary Search](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0704Binary%20Search.h) / [Guess Number Higher or Lower](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0374Guess%20Number%20Higher%20or%20Lower.h)  
### b) 一定能找到：
[Template 2](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BinarySearch2.cpp)  
i) mid>() return left-1; 找到的left>target; left-1<=target  
[Sqrt](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0069.%20Sqrt(x).h) / [First Bad Version](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0278First%20Bad%20Version.h) / [Arranging Coins](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0441Arranging%20Coins.h)  
ii) mid>=() return left; 找到的left>=target; left-1<target  
[H-Index II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0275H-Index%20II.h) / [Koko eating bananas](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0875Koko%20Eating%20Bananas.h) / [Kth Smallest Element in a sorted Matrix](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0378Kth%20Smallest%20Element%20in%20a%20Sorted%20Matrix.h)  
### c) upper_bound, lower_bound
[Max Sum of Rectangle No Larger Than K](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0363.%20Max%20Sum%20of%20Rectangle%20No%20Larger%20Than%20K.h) / [Longest Increasing Subsequence](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0300.%20Longest%20Increasing%20Subsequence.h) (Similar: [Russian Doll Envolopes](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0354.%20Russian%20Doll%20Envelopes.h)) / [Odd Even Jump](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0975.%20Odd%20Even%20Jump.h) / []()  
## 3. DFS
[Template 1](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/DFS.cpp)
## 4. BFS

## 5. Recursive
When to use: 整体和局部都有相同的性质，利用这些性质。最直接的应用就是tree, palindrome string  
[Scramble String](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0087.%20Scramble%20String.h)  

## 6. Backtracking
### a) 找出所有路径（backtrack 返回void）
i) 对vector上的元素每个都试一下, O(2^N) [Template 1](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BackTracking1.cpp)  
Combination Sum [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0039Combination%20Sum.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0040Combination%20Sum%20II.h), [III](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0216.%20Combination%20Sum%20III.h) / [Coin Change](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0322.%20Coin%20Change.h) / Subsets [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0078.%20Subsets.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0090.%20Subsets%20II.h) / [Palindrome Partitioning](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0131.%20Palindrome%20Partitioning.h) / [Letter Combinations of a Phone Number](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0017.%20Letter%20Combinations%20of%20a%20Phone%20Number.h)  
ii) O(N!)  
Permutations [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0046.%20Permutations.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0047.%20Permutations%20II.h)  
### b) 找出一条路径（backtrack 返回 bool）
[Template 2](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BackTracking2.cpp)  
[Lowest Common Ancestor of a Binary Tree](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0236Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree.h) / [Partition to K equal Sum](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0698.%20Partition%20to%20K%20Equal%20Sum%20Subsets.h) / [Word search](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0079.%20Word%20Search.h)  

## 7. Greedy
Jump Game [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0055.%20Jump%20Game.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0045.%20Jump%20Game%20II.h)  
## 6. Union Find
[Template](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/UnionFind.cpp)  
[Redundant Connection](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0684.%20Redundant%20Connection.h) / [Friend Circles](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0547.%20Friend%20Circles.h) / [Sentence Similarity II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0737.%20Sentence%20Similarity%20II.h)  
## 7. Sliding Window
[Template](https://github.com/chbyang/Leetcode/blob/master/template/SlidingWindow1.cpp)
### a) key,count
### b) key,position
[Longest Substring Without Repeating Characters](https://github.com/chbyang/Leetcode/blob/master/code/0003LongestSubstrWithoutRepeatingCharacters.h)  
## 8. Two Pointers

## 9. Tree

## 10. Stack

## 13 Queue
### a)
### b) 
## 14 Deque
[Sliding Window Max](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0239.%20Sliding%20Window%20Maximum.h)  
## 15 Bit Manipulation
[Single Number]() (Similar: [Find the Difference]())
## unordered_map
[TWO SUM](https://github.com/chbyang/Leetcode/blob/master/code/0001.%20TwoSum.h) 

## linked list
[AddTwoNumbers](https://github.com/chbyang/Leetcode/blob/master/code/0002.%20AddTwoNumbers.h)

## sum
[TWO SUM](https://github.com/chbyang/Leetcode/blob/master/code/0001.%20TwoSum.h) 

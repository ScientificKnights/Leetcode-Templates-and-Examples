# Leetcode
## 1. Dynamic Programming
When to use: 之后的结果对前面没有影响，并且存在关系 F(n)=f(F(k<n)). 解决dp问题关键是找到推进公式  
问题格式： HOW MANY?? MAXMUM/MINMUM?? TURE/FALSE?? Longest/Largest??  
### a) 1D, 找到公式后得到下一个
i) 公式只用前面一个element: [counting bits](https://github.com/chbyang/Leetcode/blob/master/code/0338Counting%20Bits.h)  
ii) 公式用前面几个elements: [House Robber I](https://github.com/chbyang/Leetcode/blob/master/code/0198House%20Robber.h), [II](https://github.com/chbyang/Leetcode/blob/master/code/0213House%20Robber%20II.h) (Similar: [Delete and Earn](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0740.%20Delete%20and%20Earn.h)) / Sum可重复排列[Coin Change](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0322.%20Coin%20Change.h) (Similar: [Combination Sum IV](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0377.%20Combination%20Sum%20IV.h)) / [Coin Path](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0656.%20Coin%20Path.h) / [4 Keys Keyboard](https://github.com/chbyang/Leetcode/blob/master/code/0651_4%20Keys%20Keyboard.h) (Similar: [Integer Break](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0343.%20Integer%20Break.h))  
iii)  扫描所有K次: Sum可重复组合[Coin Change 2](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0518.%20Coin%20Change%202.h) / Sum不重复[Partition Equal Subset Sum](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0416.%20Partition%20Equal%20Subset%20Sum.h) (Similar: [Target Sum](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0494.%20Target%20Sum.h)) / [Largest Sum of Averages](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0813.%20Largest%20Sum%20of%20Averages.h)  
iv) 公式用前面所有elements: [Number of Longest Increasing Subsequence](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0673.%20Number%20of%20Longest%20Increasing%20Subsequence.h) / [Unique Binary Search](https://github.com/chbyang/Leetcode/blob/master/code/0096Unique%20Binary%20Search%20Trees.h)  / [Perfect Squares](https://github.com/chbyang/Leetcode/blob/master/code/0279Perfect%20Squares.h) / [Word break](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0139.%20Word%20Break.h) / [2 Keys Keyboard](https://github.com/chbyang/Leetcode/blob/master/code/0650_2%20Keys%20Keyboard.h)  
### b) 2D
[Template](https://github.com/chbyang/Leetcode/blob/master/template/2D_DP1.cpp)  
小技巧，通常内存可以2D压缩为1D，如果公式是k[i][j]=k[i-1][j-1]+k[i-1][j]。可以直接存一个vector，计算时从最后算，避免覆盖  
i) 公式递进: [Edit Distance](https://github.com/chbyang/Leetcode/blob/master/code/0072Edit%20Distance.h) (Similar: [Minimum ASCII Delete Sum for Two Strings](https://github.com/chbyang/Leetcode/blob/master/code/0712Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings.h) / [Delete Operation for Two Strings](https://github.com/chbyang/Leetcode/blob/master/code/0583Delete%20Operation%20for%20Two%20Strings.h) / [Regular expression](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0010.%20Regular%20Expression%20Matching.h) / [Wildcard matching](https://github.com/chbyang/Leetcode/blob/master/code/0044Wildcard%20Matching.h) / [Interleaving String](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0097.%20Interleaving%20String.h) / [Distinct Subsequences](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0115.%20Distinct%20Subsequences.h)) / [Dungeon Game](https://github.com/chbyang/Leetcode/blob/master/code/0174Dungeon%20Game.h) / [Paint House I](https://github.com/chbyang/Leetcode/blob/master/code/0256Paint%20House.h), [II](https://github.com/chbyang/Leetcode/blob/master/code/0265Paint%20House%20II.h) / [Bomb Enemy](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0361.%20Bomb%20Enemy.h) / [Maximal Square](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0221.%20Maximal%20Square.h) / [Longest Palindromic Subsequence](https://github.com/chbyang/Leetcode/blob/master/code/0516Longest%20Palindromic%20Subsequence.h) (Similar: [Maximum Length of Repeated Subarray](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0718Maximum%20Length%20of%20Repeated%20Subarray.h) / [Largest Divisible Subset](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0368.%20Largest%20Divisible%20Subset.h))  
ii) 2D整体到下一步: [Knight Dialer](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0935.%20Knight%20Dialer.h) / [Knight Probability in Chessboard](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0688.%20Knight%20Probability%20in%20Chessboard.h) / [Out of Boundary Paths](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0576.%20Out%20of%20Boundary%20Paths.h)  
iii) 1D扩为2D, state是新的degree, 内存可2D压缩为1D: [Paint Fence](https://github.com/chbyang/Leetcode/blob/master/code/0276Paint%20Fence.h) / [Minimum Swaps To Make Sequences Increasing](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0801Minimum%20Swaps%20To%20Make%20Sequences%20Increasing.h) / [Domino and Trimino Tiling](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0790.%20Domino%20and%20Tromino%20Tiling.h) / [Odd Even Jump](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0975.%20Odd%20Even%20Jump.h) / [Best Time to Buy and Sell Stock III](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III.h), [IV](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0188.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20IV.h), [with Cooldown](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0309.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown.h)  
iv) 对角线推进: [Burst Bolloons](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0312Burst%20Balloons.h) / [Stone Game](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0877.%20Stone%20Game.h) / [Palindrome Partitioning](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0132.%20Palindrome%20Partitioning%20II.h)  
### c) Memoizatoin: Top Down
[Word Break II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0140.%20Word%20Break%20II.h) / [Race Car](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0818.%20Race%20Car.h)  
### d) 3D
[Remove Boxes](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0546.%20Remove%20Boxes) / [Cherry Pickup](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0741.%20Cherry%20Pickup.h)
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
every try must be correct if backtrack not used  
i) grid [Template 1](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/DFS.cpp)  
[Longest Increasing Path in a Matrix](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0329.%20Longest%20Increasing%20Path%20in%20a%20Matrix.h)  
ii) vector [Coin Change](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0322.%20Coin%20Change.h) / 
## 4. Backtracking
### a) 找出所有路径（backtrack 返回void）
i) 对vector上的元素每个都试一下, O(2^N) [Template 1](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BackTracking1.cpp)  
Combination Sum [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0039Combination%20Sum.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0040Combination%20Sum%20II.h), [III](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0216.%20Combination%20Sum%20III.h) / (Similar: [Shopping Offers](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0638.%20Shopping%20Offers.h)) / Subsets [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0078.%20Subsets.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0090.%20Subsets%20II.h) / [Combinations](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0077.%20Combinations.h) / [Binary Watch](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0401.%20Binary%20Watch.h) / [Palindrome Partitioning](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0131.%20Palindrome%20Partitioning.h) / [Letter Combinations of a Phone Number](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0017.%20Letter%20Combinations%20of%20a%20Phone%20Number.h)  
ii) 2D try different pos: [N Queues I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0051.%20N-Queens.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0052.%20N-Queens%20II.h) / [Sudoku Solver](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0037.%20Sudoku%20Solver)  
iii) O(N!): Permutations [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0046.%20Permutations.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0047.%20Permutations%20II.h) (Similar: [Number of Squareful Arrays](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0996.%20Number%20of%20Squareful%20Arrays.h))  
iv) tree: [Binary Tree Paths](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0257.%20Binary%20Tree%20Paths.h)  
### b) 找出一条路径（backtrack 返回 bool）
[Template 2](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/BackTracking2.cpp)  
[Lowest Common Ancestor of a Binary Tree](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0236Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree.h) / [Word search](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0079.%20Word%20Search.h) / [Reconstruct Itinerary](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0332.%20Reconstruct%20Itinerary.h)  
### c) 找出多条路径，组成一个路径
[Partition to K equal Sum](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0698.%20Partition%20to%20K%20Equal%20Sum%20Subsets.h)
## 5. BFS
[Template]()  
i) Result related to level: [01 Matrix](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0542.%2001%20Matrix.h)  
ii) Graph can go back to previous node: [Maze I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0490.%20The%20Maze.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0505.%20The%20Maze%20II.h), [III](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0499.%20The%20Maze%20III.h)  
## 6. Recursive
When to use: 整体和局部都有相同的性质，利用这些性质。最直接的应用就是tree, palindrome string  
i) Number: [Permutation Sequence](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0060.%20Permutation%20Sequence.h)  
ii) String: [Scramble String](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0087.%20Scramble%20String.h)  
## 7. Greedy
Jump Game [I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0055.%20Jump%20Game.h), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0045.%20Jump%20Game%20II.h) / [Course Schedule III]() / [Coin Change](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0322.%20Coin%20Change.h)  
## 6. Union Find
[Template](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/template/UnionFind.cpp)  
[Redundant Connection](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0684.%20Redundant%20Connection.h) / [Friend Circles](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0547.%20Friend%20Circles.h) / [Sentence Similarity II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0737.%20Sentence%20Similarity%20II.h) / [Most Stones Removed with Same Row or Column](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0947.%20Most%20Stones%20Removed%20with%20Same%20Row%20or%20Column.h)  
## 7. Sliding Window
[Template](https://github.com/chbyang/Leetcode/blob/master/template/SlidingWindow1.cpp)  
i) key,count  
ii) key,position [Longest Substring Without Repeating Characters](https://github.com/chbyang/Leetcode/blob/master/code/0003LongestSubstrWithoutRepeatingCharacters.h)  
## 8. Two Pointers
## 9. Linked list
[AddTwoNumbers](https://github.com/chbyang/Leetcode/blob/master/code/0002.%20AddTwoNumbers.h)
## 10. Tree

## 11. Stack

## 12. Queue

## 13. Deque
[Sliding Window Max](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0239.%20Sliding%20Window%20Maximum.h)  
## 14. Unordered_map
[TWO SUM](https://github.com/chbyang/Leetcode/blob/master/code/0001.%20TwoSum.h) 
## 15. Graph
### a)
### b) Topological sort
[Course Schedule I](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0207.%20Course%20Schedule), [II](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0210.%20Course%20Schedule%20II.h) / [Sequence Reconstruction](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0444.%20Sequence%20Reconstruction.h) / [Alien Dictionary](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/0269.%20Alien%20Dictionary.h)  
## 16. Bit Manipulation
[Single Number]() (Similar: [Find the Difference]()) / [Convert to Base -2](https://github.com/chbyang/Leetcode-Templates-and-Examples/blob/master/code/1017.%20Convert%20to%20Base%20-2.h) https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

## sum
[Two Sum](https://github.com/chbyang/Leetcode/blob/master/code/0001.%20TwoSum.h) 

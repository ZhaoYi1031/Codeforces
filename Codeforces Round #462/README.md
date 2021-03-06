# Codeforces Round #462

[传送门](http://codeforces.com/contest/934)

对我来说是一次比较好的大涨rating的比赛，然而遗憾没抓住。

## A
水题。有坑，我们房间一堆hack，我一直在考虑C题，没有去考虑hack别人。

## B
水题。也有坑，我们房间一堆hack，我一直在考虑C题，没有去考虑hack别人。

## C
题目的大意就是：给你一个序列，你可以把其中的一段进行翻转。即[ai, ai+1,…..aj-1, aj]翻转成[aj, aj-1…… ai+1,ai]。只能翻转一次，要求使得翻转后的序列，它的最长非递减子序列的长度， 达到最大。求这个值。例如样例

>n = 10
序列是：1 1 2 2 2 1 1 2 2 
我们翻转区间[3,7]
序列变成 [1, 1, 1, 1, 2, 2, 2, 2, 2, 1]
此时的最长非递减序列长度达到9

最一开始的思路是直接找到最长的那段非递减的子序列，进行翻转，然后求一边LIS。这种思路是错的，例如序列[1,2,3,1,2]，我们需要将[2,4]翻转，然后此时[1,1,3,2,2]达到最大为4。

和LYJ讨论的做法如下：
在中间找到一个子序列进行翻转，然后此时我们可以看成是三个子序列的拼接，左子序列，中间子序列，右子序列。记中序列的区间为[i,j]，我们将该问题转化为：**求左边和右边子序列的最长不降子序列的长度，中间子序列最长不升子序列。为了能够让三段的和直接相加，我们在求左右子序列的LIS的时候，左边只考虑<=a[j]，右边只考虑>=a[i]的。这昂我们就可以三段相加**

具体的实现是：我们首先对左部和右部进行初始化，左部计算f[i][j]--1~i中所有不超过j的数的最长不降子序列的长度。这个的求法很多，时间复杂度应该是O(nlogn)*O(max(a[i]))，在我们这题由于a[i]只能为1，2.我们可以直接求f[i][1]与f[i][2].

同理计算g[i][j]:在i~n中所有大于等于j的值的最长不降子序列的长度。

最重要的就是求中间的LIS了。这个我们可以通过nlogn算法。这个思路的核心在于我们在求LIS时，维护一个stack，它代表的是所有结果为i的最长子序列的最小值。维护这个非递减序列，使得我们每次能够找到一个更优的之前的序列进行更新。由于这个序列的有序性，我们的更新操作为O(logn)。所以我们求中间这个LIS时，尽管遍历i和j需要O($n^{2}$)复杂度，但是对于同一个i，左边都是固定的，直接和j一起套用那个LIS。因此时间复杂度为O($n^{2}logn$), n的范围是2000，因此可以过。



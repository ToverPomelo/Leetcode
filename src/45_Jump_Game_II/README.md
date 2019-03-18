# 45. Jump Game II
&emsp;&emsp;原题地址：[https://leetcode.com/problems/jump-game-ii/](https://leetcode.com/problems/jump-game-ii/) <br/>

# 题目描述
&emsp;&emsp;输入的数组（vector）中的数表示能跳的距离，求从数组第一个数跳到最后一个数所用的最少次数。 <br/>

# 思路
&emsp;&emsp;首先看到题目第一时间想到的就是用dp（动态规划）了。用一个dp数组存当前位置要用的（最少）次数，设dp数组最后一个为0（站在终点就不用跳了），然后从后到前更新dp数组(遍历能跳到的点计算最少次数再加一)，直到更新完数组第一个数。 <br/>
&emsp;&emsp;题目的样例有个大坑，最后一个测试样例如果不做优化的话很容易会TLE...优化做在了代码第34行（只是针对特殊输入的优化。。没什么好说的）。 <br/>

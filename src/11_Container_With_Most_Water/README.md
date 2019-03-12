# 11. Container With Most Water
&emsp;&emsp;原题地址：[https://leetcode.com/problems/container-with-most-water/](https://leetcode.com/problems/container-with-most-water/) <br/>

# 题目解析
&emsp;&emsp;给定一堆边，找两条边使得它们夹着的地方形成的缸“装的水最多”，这个缸是二维的，高是边中短的一条（木桶原理），宽是两边的距离。 <br/>

# 思路
&emsp;&emsp;首先用公式来表示缸的面积：令左边的边在数组的下标是l，右边的边在数组的下标是r，数组是arr，则可以得到容量为：V = (r-l) * min(arr[l],arr[r])。 <br/>
&emsp;&emsp;然后就可以暴力了。。。 <br/>
&emsp;&emsp;另外瞄了一眼答案有一种做法是可以用贪心法的，可以达到O(n)的速度，（暴力是O(n^2)），解释和证明略（咕咕咕） <br/>

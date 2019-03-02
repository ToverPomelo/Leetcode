# 33. Search in Rotated Sorted Array
&emsp;&emsp;原题地址：[https://leetcode.com/problems/search-in-rotated-sorted-array/](https://leetcode.com/problems/search-in-rotated-sorted-array/)  <br/>
## 题目描述
&emsp;&emsp;实现对一种特殊的数组的搜索（输入要搜索的数字，返回对应下标或用-1表示没找到）。  <br/>
&emsp;&emsp;这种特殊数组的格式：首先把一个按升序排列的数组在随机位置切成两半（如【0,1,2,4,5,6,7】可以切成【0,1,2】和【4，5，6，7】），再把两个数组调换再拼接，如（【0，1，2】、【4，5，6，7】调换成【4，5，6，7】、【0，1，2，】再拼接成【4，5，6，7，0，1，2】）。其中切割的点称为pivot（解法中也不需要知道pivot是切割点左边还是右边的数字，所以就不深究了），pivot在计算前是未知的。  <br/>

## 思路
&emsp;&emsp;对于排好序的数组的搜索常用的方法是二分搜索，但因为这里的数组存在pivot，不能用普通的二分搜索，所以要对二分搜索进行一下改造。  <br/>
&emsp;&emsp;解法没有什么特殊的技巧，就是分类讨论：  <br/>
&emsp;&emsp;对于二分搜索的每一步，首先分成两类，pivot在搜索范围里的和pivot不在搜索范围里的。如果pivot不在搜索范围内的话，则说明该范围里的数是有序的，用普通的二分搜索即可；如果pivot在搜索范围里的话，则再分两种情况：pivot在搜索范围的左半部分和pivot在搜索范围的右半部分（这里先令中间的数为midNum,类似普通的二分搜索那样把搜索范围减半，然后看要搜索哪一边）。  <br/>
&emsp;&emsp;先说pivot在左边的情况，这时又要分两类（emm），一类是target比midNum大且没有越界（也就是比范围内最右边的数小，因为pivot左边还有更大的数），这时候应该搜索范围内的右半边；另一类其实是有两种情况的集合，分别是target小于midNum和target在右边但是越界了，这两种情况都应该搜索所在范围的左半边。  <br/>
&emsp;&emsp;pivot在右边的情况和pivot在左边的情况差不多，也是分成两类：一类是target比midNum小且没有向左越界，这时应该搜索左半边；另一类也是两种情况的集合，分别是target比midNum大和target比midNum小但是越界了，这两种情况都是搜索右半边。  <br/>
&emsp;&emsp;上面是所有的分类情况，其中还要实现的一个是怎么判断pivot在不在一个搜索范围内（判断pivot在哪一边时也要用到）：令数组的第一个数为headNum，最后一个数为tailNum，搜索范围的第一个数为newHeadNum，最后一个数为newTailNum，经观察得pivot在搜索范围内与以下情况等同：newHeadNum大于等于headNum且newTailNum小于等于tailNum且headNum大于等于tailNum（最后一种情况是防止原数组是有序的）。  <br/>
&emsp;&emsp;举个栗子：【4，5，6，7，0，1，2】，如果搜索范围是【6，7，0，1】的话，因为有6>=4且1<=2且4>=2，所以pivot在该范围内。  <br/>

## 题解
&emsp;&emsp;看文字的话可能有点模糊，看代码的话会清晰点。代码分成了两个文件，一个是递归版本的，一个是迭代版本的，原本以为迭代会比递归省一点内存就改成了迭代，谁知道耗的内存还多了。。。  <br/>

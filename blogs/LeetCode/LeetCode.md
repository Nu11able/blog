---
title: 力扣刷题记录
date: '2022-02-26 00:58:00'
tags:
 - c++
 - LeetCode
 - dp
categories:
 - LeetCode
---

# 力扣刷题记录

## 题目描述：[2016.增量元素之间的最大差值](https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/)
**思路：** 首先0<=i<j<n且nums\[i\]<nums\[j\]，在(i,j)这样一个范围中找一对满足条件的数据，对于这样的问题啥也别说了，无脑dp

**公式：**

$dp[i][j] = nums[i] >= nums[j] ? -1 : nums[j] - nums[i]$

$dp[i][j] = max(dp[i][j], dp[i + 1][j], dp[i][j - 1])$

```cpp
class Solution {
public:
	int maximumDifference(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		for (int k = 1; k < n; k++) {
			for (int i = 0; i + k < n; i++) {
				dp[i][i + k] = nums[i] >= nums[i + k] ? -1 : nums[i + k] - nums[i];
				dp[i][i + k] = max(dp[i][i + k], max(dp[i + 1][i + k], dp[i][i + k - 1]));
			}
		}
		return dp[0][n - 1];
	}
};
```

提交了代码后看了官方题解顿时感慨官方题解就是官方题解，够精辟。[官方题解](https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/solution/zeng-liang-yuan-su-zhi-jian-de-zui-da-ch-i0wk/)
```c++
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};
```

`记录日期：2022/02/26`
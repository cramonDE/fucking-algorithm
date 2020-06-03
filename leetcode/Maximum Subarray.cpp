// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.


// 求子串加和的最大值

// 其实不需要考虑太复杂的算法逻辑，这里其实就是一个数组循环不断加和求最大的过程。
// 1. result 用于每次计算结果之后的比较，返回最大的数值，ans 是中间计算过程，每次循环都会有 result 和 ans 的对比
// 2. 核心步骤，只分两种情况，只有在加上 num[i] 后仍为正，且 ans 本身为正，这种情况（两个正数）下才会相加，其他情况都直接重新赋值

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + ans > 0 && ans > 0) {
                ans += nums[i];
            } else {
                ans = nums[i];
            }
            result = max(result, ans);
        }
        return result;
    }
};




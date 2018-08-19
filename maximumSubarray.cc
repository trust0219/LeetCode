#include <iostream>
#include <vector>
using namespace std;
/*

Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum.


Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0], totalSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      // Current max sum is either the current element OR current element +
      // Previous Maximum subarray)
      currentSum = max(nums[i], currentSum + nums[i]);

      // If the current maximum array sum is greater than the global total.
      // Update it
      totalSum = max(totalSum, currentSum);
    }
    return totalSum;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << s.maxSubArray(nums) << endl;
  nums = {-2, -1};
  cout << s.maxSubArray(nums) << endl;
}

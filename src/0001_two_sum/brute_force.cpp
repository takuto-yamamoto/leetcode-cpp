#include <vector>

class Solution {
public:
    // vectorは配列のように長さを固定する必要がない
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        // O(n^2)なので非効率
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                  return  { i, j };
                }
            }
        }

        return {};
    }
};
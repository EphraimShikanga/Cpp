#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.count(complement) > 0) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }

    return {};
}

int main() {
    std::vector<int> nums = {2, 11, 15, 93, 12, 57, 41, 25, 86, 64, 38, 73, 5, 68, 19, 70, 99, 81, 47, 53, 92, 10, 88};
    int target = 132;

    std::vector<int> result = twoSum(nums, target);

    std::cout << result[0] << " " << result[1] << std::endl;

    return 0;
}
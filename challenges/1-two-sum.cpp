#include <vector>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
    static std::vector<int> twoSum(const std::vector<int> &nums, const int target)
    {
        std::unordered_map<int, int> pos;
        pos.reserve(nums.size());

        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int need = target - nums[i];

            auto it = pos.find(need);
            if (it != pos.end())
            {
                return {it->second, i};
            }

            pos[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main()
{
    const std::vector<int> nums{2, 7, 11, 15};

    std::vector<int> result = Solution::twoSum(nums, 9);

    std::cout << result[0] << ", " << result[1] << '\n';
}
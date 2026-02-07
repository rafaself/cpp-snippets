#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution
{
public:
    static int lengthOfLongestSubstring(const std::string &s)
    {
        std::unordered_map<char, int> last;
        last.reserve(128);

        int best = 0;
        int start = 0;

        for (int i = 0; i < static_cast<int>(s.size()); ++i)
        {
            char c = s[i];

            auto it = last.find(c);
            if (it != last.end() && it->second >= start)
            {
                start = it->second + 1;
            }

            last[c] = i;
            best = std::max(best, i - start + 1);
        }

        return best;
    }
};

int main()
{
    int count = Solution::lengthOfLongestSubstring("abcabcbb");
    std::cout << "Final count: " << count << '\n'; // 3

    count = Solution::lengthOfLongestSubstring("bbbbbbbb");
    std::cout << "Final count: " << count << '\n'; // 1

    count = Solution::lengthOfLongestSubstring("pwwkew");
    std::cout << "Final count: " << count << '\n'; // 3

    count = Solution::lengthOfLongestSubstring(" ");
    std::cout << "Final count: " << count << '\n'; // 1
}

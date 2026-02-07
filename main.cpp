#include <iostream>
#include <unordered_map>

class Solution
{
public:
    static int lengthOfLongestSubstring(std::string s)
    {
        int count{0};
        int temp{0};
        std::unordered_map<char, int> content;

        for (char c : s)
        {
            if (content.find(c) != content.end())
            {
                if (temp > count)
                {
                    count = temp;
                }
                temp = 0;
                content.clear();
            }
            temp++;
            content.emplace(c, 1);

            // std::cout << "letter: " << c << '\n';
            // std::cout << "count: " << count << " - temp: " << temp << '\n';
            // std::cout << "---------------------------\n";
        }

        return count;
    }
};

int main()
{
    int count = Solution().lengthOfLongestSubstring("abcabcbb");
    std::cout << "Final count: " << count << '\n';
    count = Solution().lengthOfLongestSubstring("bbbbbbbb");
    std::cout << "Final count: " << count << '\n';
    count = Solution().lengthOfLongestSubstring("pwwkew");
    std::cout << "Final count: " << count << '\n';
}

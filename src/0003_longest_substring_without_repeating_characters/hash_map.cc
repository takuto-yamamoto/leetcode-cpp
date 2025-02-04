#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int max_length = 0;
        unordered_map<char, int> char_map; // 文字に対してポインタを管理するハッシュマップ
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (char_map.count(s[right]) == 0 || char_map[s[right]] < left)
            {
                char_map[s[right]] = right;
                max_length = max(max_length, right - left + 1);
            }
            else
            {
                left = char_map[s[right]] + 1;
                char_map[s[right]] = right;
            }
        }

        return max_length;
    }
};
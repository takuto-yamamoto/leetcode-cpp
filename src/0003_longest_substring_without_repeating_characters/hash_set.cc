#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int max_length = 0;
        unordered_set<char> char_set;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            // ハッシュテーブルに対してcountはO(1)
            if (char_set.count(s[right]) == 0)
            {
                char_set.insert(s[right]);
                max_length = max(max_length, right - left + 1);
            }
            else
            {
                // whileを使用しているが、leftは0~n-2までしか動かずwhile内の処理もn-2回までしか実行されないのでO(n)
                while (char_set.count(s[right]))
                {
                    char_set.erase(s[left]);
                    left++;
                }
                char_set.insert(s[right]);
            }
        }

        return max_length;
    }
};
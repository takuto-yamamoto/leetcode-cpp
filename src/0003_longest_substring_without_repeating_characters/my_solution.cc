#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string answer = "";
        string current_word = "";

        for (char character : s)
        {
            // 解説: findはO(n)なので、O(n^2)になってしまう
            if (current_word.find(character) != string::npos)
            {
                vector<string> split_result = split(current_word, character);
                if (split_result.size() >= 2)
                {
                    current_word = split_result[1];
                }
                else if (split_result.size() == 1)
                {
                    current_word = character;
                }
                if (current_word[0] != character)
                {
                    current_word += character;
                }
            }
            else
            {
                current_word += character;
            }

            if (current_word.length() >= answer.length())
            {
                answer = current_word;
            }
        }

        if (current_word.length() > answer.length())
        {
            answer = current_word;
        }

        return static_cast<int>(answer.length());
    }

    vector<string> split(const string &s, char delim)
    {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            elems.push_back(item);
        }
        return elems;
    }
};

int main()
{
    Solution sol;
    string s = "pwwkew";
    cout << sol.lengthOfLongestSubstring(s) << endl;
}
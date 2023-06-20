// You are given a string s consisting only of lowercase English letters.
// In one move, you can select any two adjacent characters of s and swap them.
// Return the minimum number of moves needed to make s a palindrome.
// Note that the input will be generated such that s can always be converted to a palindrome.

// Example:
// Input: s = "letelt"
// Output: 2

#include <bits/stdc++.h>
using namespace std;

int minMovesToMakePalindrome(string s)
{
    int len = s.size();

    int left = 0;
    int right = len - 1;
    int center = -1;

    int count = 0;
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left += 1;
            right -= 1;
            continue;
        }

        int r = right - 1;
        while (left < r)
        {
            if (s[left] == s[r])
            {
                break;
            }
            r--;
        }

        if (left == r)
        {
            center = left;
            left += 1;
            continue;
        }

        while (r < right)
        {
            swap(s[r], s[r + 1]);
            count += 1;
            r += 1;
        }

        left += 1;
        right -= 1;
    }

    if (center != -1)
    {
        count += abs(center - (len / 2));
    }
    cout << s << endl;
    return count;
}

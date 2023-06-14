#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    unordered_set<string> us(wordList.begin(), wordList.end());
    us.erase(beginWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord)
        {
            return steps;
        }

        int len = word.size();
        for (int i = 0; i < len; i++)
        {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;

                if (us.find(word) != us.end())
                {
                    us.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }

    return 0;
}

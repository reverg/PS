class Solution
{
public:
    string rearrangeString(string s, int k)
    {
        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;

        priority_queue<pair<int, int>> free;
        for (int i = 0; i < 26; i++)
            if (freq[i])
                free.push({freq[i], i});

        string ans;
        queue<pair<int, int>> busy; // queue stores the characters that cannot be used now.
        while (ans.size() != s.size())
        {
            int index = ans.size();

            // Insert the character that could be used now into the free heap.
            if (!busy.empty() && (index >= busy.front().first))
            {
                auto q = busy.front();
                busy.pop();
                free.push({freq[q.second], q.second});
            }

            if (free.empty())
                return "";

            int currChar = free.top().second;
            free.pop();
            ans += currChar + 'a';
            freq[currChar]--;
            if (freq[currChar] > 0)
                busy.push({index + k, currChar});
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (99.94%, 81.67%). #621에서 실제 배열을 구하는 문제.
현재 사용 가능한 문자와 대기 중인 문자를 각각 우선순위 큐와 큐로 따로 관리한다.
매 인덱스마다 사용 가능한 문자 중 가장 많이 남은 문자를 선택해서 사용.
사용한 문자는 큐에 넣어서 다음에 사용 가능한 시기가 올 때까지 대기시킨다.
시간 O((N+K) log K). heap 만드는데 KlogK, 인덱스마다 뽑는거 합이 NlogK다. 공간은 O(K).

Greedy로 O(N), O(K)에 풀린다고 하는데 증명이 어렵다. 잘 모르겠음.
class Solution
{
public:
    string rearrangeString(string s, int k)
    {
        unordered_map<char, int> freqs;
        int maxFreq = 0;
        // Store the frequency, and find the highest frequency.
        for (char c : s)
        {
            freqs[c]++;
            maxFreq = max(maxFreq, freqs[c]);
        }

        unordered_set<char> mostChars;
        unordered_set<char> secondChars;
        // Store all the characters with the highest and second highest frequency - 1.
        for (pair<char, int> charPair : freqs)
        {
            if (charPair.second == maxFreq)
                mostChars.insert(charPair.first);
            else if (charPair.second == maxFreq - 1)
                secondChars.insert(charPair.first);
        }

        // Create maxFreq number of different strings.
        string segments[maxFreq];
        // Insert one instance of characters with frequency maxFreq & maxFreq -
        // 1 in each segment.
        for (int i = 0; i < maxFreq; i++)
        {
            for (char c : mostChars)
                segments[i] += c;

            // Skip the last segment as the frequency is only maxFreq - 1.
            if (i < maxFreq - 1)
                for (char c : secondChars)
                    segments[i] += c;
        }

        int segmentId = 0;
        // Iterate over the remaining characters, and for each, distribute the
        // instances over the segments.
        for (pair<char, int> charPair : freqs)
        {
            char currChar = charPair.first;

            // Skip characters with maxFreq or maxFreq - 1
            // frequency as they have already been inserted.
            if (mostChars.find(currChar) != mostChars.end() ||
                secondChars.find(currChar) != secondChars.end())
                continue;

            // Distribute the instances of these characters over the segments in
            // a round-robin manner.
            for (int freq = freqs[currChar]; freq > 0; freq--)
            {
                segments[segmentId] += charPair.first;
                segmentId = (segmentId + 1) % (maxFreq - 1);
            }
        }

        // Each segment except the last should have exactly K elements; else,
        // return "".
        for (int i = 0; i < maxFreq - 1; i++)
            if (segments[i].size() < k)
                return "";

        string ans;
        // Join all the segments and return them.
        for (string s : segments)
            ans += s;

        return ans;
    }
};
*/
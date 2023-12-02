#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Trie
{
private:
    Trie *child[26];
    bool is_leaf = false;

public:
    Trie()
    {
        fill(child, child + 26, nullptr);
    }

    void insert(string &word, int word_size, int idx)
    {
        if (idx >= word_size)
        {
            is_leaf = true;
            return;
        }

        int word_pos = word.at(idx) - 'a';
        if (child[word_pos] == NULL)
            child[word_pos] = new Trie();

        child[word_pos]->insert(word, word_size, idx + 1);
    }

    bool find(string &word, int word_size, int idx)
    {
        if (idx >= word_size)
            return is_leaf;
        else
        {
            int word_pos = word.at(idx) - 'a';
            if (child[word_pos] == NULL)
                return false;

            return child[word_pos]->find(word, word_size, idx + 1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Trie root;
    string input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        root.insert(input, input.size(), 0);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        if (root.find(input, input.size(), 0))
            cnt++;
    }

    cout << cnt << '\n';
}
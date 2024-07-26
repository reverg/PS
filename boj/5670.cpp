#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Trie
{
private:
    Trie *childs[26];
    int child_cnt;
    bool is_root, is_leaf;

public:
    Trie(bool is_root)
    {
        fill(childs, childs + 26, nullptr);
        this->child_cnt = 0;
        this->is_root = is_root;
        this->is_leaf = false;
    }

    ~Trie()
    {
        for (int i = 0; i < 26; i++)
            if (childs[i] != NULL)
                delete childs[i];
    }

    void insert(string &word, int word_size, int idx)
    {
        if (idx >= word_size)
        {
            is_leaf = true;
            return;
        }

        int word_pos = word.at(idx) - 'a';
        if (childs[word_pos] == NULL)
        {
            childs[word_pos] = new Trie(false);
            child_cnt++;
        }

        childs[word_pos]->insert(word, word_size, idx + 1);
    }

    int find(string &word, int word_size, int idx, int cnt)
    {
        if (idx >= word_size)
            return cnt;

        int word_pos = word.at(idx) - 'a';
        if (is_root || child_cnt > 1 || is_leaf)
            cnt++;

        return childs[word_pos]->find(word, word_size, idx + 1, cnt);
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int N;
    cout << fixed << setprecision(2);

    while (cin >> N)
    {
        vector<string> words(N);
        for (int i = 0; i < N; i++)
            cin >> words[i];

        Trie root = Trie(true);
        for (int i = 0; i < words.size(); i++)
            root.insert(words[i], words[i].size(), 0);

        int tot = 0;
        for (int i = 0; i < words.size(); i++)
            tot += root.find(words[i], words[i].size(), 0, 0);

        cout << (double)tot / N << '\n';
    }
}
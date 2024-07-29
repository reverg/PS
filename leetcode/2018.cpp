class Solution
{
    bool same(vector<char> &line, int start, int end, string &word)
    {
        int l = word.length();
        if (end - start + 1 != l)
            return false;

        int overlap = 0;
        for (overlap = 0; overlap < l; overlap++)
        {
            if (line[start + overlap] != ' ' &&
                line[start + overlap] != word[overlap])
                break;
        }
        if (overlap == l)
            return true;

        for (overlap = 0; overlap < l; overlap++)
        {
            if (line[end - overlap] != ' ' &&
                line[end - overlap] != word[overlap])
                break;
        }
        return overlap == l;
    }

    bool match(vector<vector<char>> &board, string &word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n;)
            {
                while (i < n && board[j][i] == '#')
                    i++;
                int start = i;
                while (i < n && board[j][i] != '#')
                    i++;
                if (same(board[j], start, i - 1, word))
                    return true;
            }
        }

        return false;
    }

public:
    bool placeWordInCrossword(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<char>> board_trans(n, vector<char>(m));
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                board_trans[j][i] = board[i][j];

        return match(board, word) || match(board_trans, word);
    }
};

/*
시뮬레이션 문제. 줄별로 확인해서 가능한 부분을 찾고 word와
matching해보는 방식 자체는 간단하나 예쁘게 구현하기가 힘들다.
많아야 상하좌우 4번만 확인하므로 시간복잡도는 O(NM).
*/
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    string p;
    int n;
    string seq;
    string num = "";

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        deque<int> dq;
        cin >> p >> n;

        // get numbers
        cin >> seq;
        if (n != 0)
        {
            for (int j = 1; j < seq.length(); j++)
            {
                if (isdigit(seq[j]))
                    num += seq[j];
                else
                {
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }

        // excecute function sequence
        bool rotated = false;
        bool error = false;
        for (int j = 0; j < p.length(); j++)
        {
            if (p[j] == 'R')
                rotated = !rotated;
            else
            {
                if (dq.empty())
                {
                    cout << "error\n";
                    error = true;
                    break;
                }

                if (!rotated)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        // print result
        if (!error)
        {
            cout << '[';
            if (dq.size() != 0)
            {
                while (dq.size() >= 2)
                {
                    if (!rotated)
                    {
                        cout << dq.front() << ",";
                        dq.pop_front();
                    }
                    else
                    {
                        cout << dq.back() << ",";
                        dq.pop_back();
                    }
                }
                cout << dq.front();
            }
            cout << "]\n";
        }
    }
}
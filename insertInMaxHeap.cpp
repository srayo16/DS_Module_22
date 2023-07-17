#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        int cur_idx = v.size() - 1;
        // cout << cur_idx << endl;

        while (cur_idx != 0)
        {
            int parentIdx = (cur_idx - 1) / 2;

            // cout << parentIdx << endl;
            if (v[parentIdx] < v[cur_idx])
                swap(v[parentIdx], v[cur_idx]);
            else
                break;

            cur_idx = parentIdx;
        }
    }

    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;
}
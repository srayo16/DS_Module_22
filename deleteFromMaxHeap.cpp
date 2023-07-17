#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int x)
{
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

void deleting(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();

    int curr = 0;

    while (true)
    {
        int leftIdx = (curr * 2) + 1;
        int rightIdx = (curr * 2) + 2;
        int lastIdx = v.size() - 1;

        if (leftIdx <= lastIdx && rightIdx <= lastIdx)
        {
            // duitai ache

            if (v[leftIdx] >= v[rightIdx] && v[leftIdx] > v[curr])
            {
                swap(v[leftIdx], v[curr]);
                curr = leftIdx;
            }
            else if (v[rightIdx] >= v[leftIdx] && v[rightIdx] > v[curr])
            {
                swap(v[rightIdx], v[curr]);
                curr = rightIdx;
            }
            else
            {
                break;
            }
        }
        else if (leftIdx <= lastIdx)
        {
            if (v[leftIdx] > v[curr])
            {
                swap(v[leftIdx], v[curr]);
                curr = leftIdx;
            }
            else
            {
                break;
            }
        }
        else if (rightIdx <= lastIdx)
        {
            if (v[rightIdx] > v[curr])
            {
                swap(v[rightIdx], v[curr]);
                curr = rightIdx;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void printHeap(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(v, x);
    }

    deleting(v);

    printHeap(v);

    return 0;
}
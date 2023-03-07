#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);    cin.tie(NULL);

    multiset<int>heap;
    int q, n, num;
    char mode;

    cin >> q;

    while (q--)
    {
        cin >> n;

        heap.clear();
        while (n--)
        {
            cin >> mode >> num;

            if (mode == 'I')
                heap.insert(num);
            else if (mode == 'D' && heap.size())
            {
                if (num == -1)
                    heap.erase(heap.begin());
                else
                    heap.erase(--heap.end());
            }
            /*
            for (pair<int, int> k : heap)
                cout << k.first << ' ';
            cout << "\n\n";
            */
        }
        if (!heap.size())
            cout << "EMPTY\n";
        else
            cout << *(--heap.end()) << ' ' << *heap.begin() << '\n';
    }

    return (0);
}
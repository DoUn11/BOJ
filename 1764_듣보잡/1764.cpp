#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);    cin.tie(NULL);

    int n, m;
    int x = 0, y = 0, cmp;
    vector<string>listen;
    vector<string>see;
    vector<string>result;
    string tmp;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        listen.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        see.push_back(tmp);
    }

    sort(listen.begin(), listen.end());
    sort(see.begin(), see.end());

    while (x < n && y < m)
    {
        cmp = listen[x].compare(see[y]);

        if (!cmp)
        {
            result.push_back(listen[x]);
            x++, y++;
        }
        
        else if (cmp > 0)
            y++;
        else if (cmp < 0)
            x++;
    }

    cout << result.size() << '\n';

    for (string str : result)
        cout << str << '\n';

    return (0);
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(nullptr);

    ll n, m, tmp1, tmp2, mnNum, kevin, mn = 9999999999999LL;

    cin >> n >> m;

    vector< vector<ll> >adjList(n + 1);
    vector< ll >visited(n + 1);

    for(ll i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;

        adjList[tmp1].push_back(tmp2);
        adjList[tmp2].push_back(tmp1);
    }

    for(ll i = 1; i <= n; i++)
    {
        queue< pair<ll, ll> >que;

        for(auto&p : adjList[i])
            que.push(make_pair(p, 1));

        kevin = 0;

        visited[i] = i;
        while(!que.empty())
        {
            auto qf = que.front();
            que.pop();

            visited[qf.first] = i;
            kevin += qf.second;

            for(auto&p : adjList[qf.first])
            {
                if(visited[p] != i)
                    que.push(make_pair(p, qf.second + 1));
            }
        }

        if (kevin < mn)
        {
            mn = kevin;
            mnNum = i;
        }
    }

    cout << mnNum;
    return (0);
}
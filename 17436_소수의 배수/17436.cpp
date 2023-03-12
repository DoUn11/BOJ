#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(nullptr);

    ll n, m, plusMinus, toDivide, result = 0;

    cin >> n >> m;
    vector<ll> primes(n);

    for(auto& p : primes)
        cin >> p;

    for(ll i = 1; i < (1<<n); i++)
    {
        plusMinus = 0;
        toDivide = 1;
        for(ll j = 0; j < n; j++)
        {
            if(i & (1<<j))
            {
                plusMinus++;
                toDivide *= primes[j];
            }
        }
        result += m / ((plusMinus & 1) ? toDivide : -toDivide);
    }

    cout << result;
    return (0);
}
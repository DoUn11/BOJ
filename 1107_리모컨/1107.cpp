#include<bits/stdc++.h>

using namespace std;

bool is_possible(int ck, int num)
{
    if(!num)
        return (!(ck & 1));

    while (num)
    {
        if (ck & (1 << (num % 10)))
            return (false);
        num /= 10;
    }

    return (true);
}

int count_num(int num)
{
    int ret = 0;

    if (!num)
        return (1);

    while (num)
    {
        ret++;
        num /= 10;
    }

    return (ret);
}

int main()
{
    ios_base::sync_with_stdio(NULL);    cin.tie(NULL);

    int n, m, tmp, result;
    int ck = 0;

    cin >> n >> m;
    
    result = abs(n - 100);

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        ck |= 1 << tmp;
    }

    for (int i = 0; i <= 500000; i++)
    {
        if (n - i >= 0 && is_possible(ck, n - i))
        {
            result = min(result, i + count_num(n - i));
            break ;
        }

        if (is_possible(ck, n + i))
        {
            result = min(result, i + count_num(n + i));
            break ;
        }
    }

    cout << result;
    return (0);
}
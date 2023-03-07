#include<bits/stdc++.h>

using namespace std;

vector< vector<int> > input(int *n)
{
    ios_base::sync_with_stdio(NULL);    cin.tie(NULL);

    vector< vector<int> > v;

    cin >> *n;

    v.resize(*n);
    for (int i = 0; i < *n; i++)
        v[i].resize(*n);

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
            cin >> v[i][j];
    }

    return (v);
}

void paper(vector< vector<int> >*field, int x, int y, int size, int *b, int *w)
{
    const int endx = x + size;
    const int endy = y + size;

    bool is_blue = 1;
    bool is_white = 1;

    for (int i = x; i < endx; i++)
    {
        for (int j = y; j < endy; j++)
        {
            is_blue &= (*field)[i][j];
            is_white &= !(*field)[i][j];
        }
    }

    *b += is_blue;
    *w += is_white;

    if (!is_blue && !is_white)
    {
        paper(field, x, y, size/2, b, w);
        paper(field, (x + endx) / 2, y, size/2, b, w);
        paper(field, x, (y + endy) / 2, size/2, b, w);
        paper(field, (x + endx) / 2, (y + endy) / 2, size/2, b, w);
    }

    return ;
}

void print(int blue, int white)
{
    cout << white << '\n' << blue;
    return ;
}

int main()
{
    vector< vector<int> >field;
    int n, blue, white;

    field = input(&n);
    paper(&field, 0, 0, n, &blue, &white);
    print(blue, white);

    return (0);
}
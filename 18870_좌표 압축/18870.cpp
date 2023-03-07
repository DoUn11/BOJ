#include<bits/stdc++.h>

using namespace std;

vector<int> input(int *n)
{
     ios_base::sync_with_stdio(NULL);    cin.tie(NULL);

    vector<int> ret;
    int tmp;

     cin >> *n;

     for(int i = 0; i < *n; i++)
     {
        cin >> tmp;
        ret.push_back(tmp);
     }

     return (ret);
}

vector<int> zipped(vector<int>input_vec, int n)
{
    vector<int> ret;

    map<int, int> ziplist;
    int zipnum = 0;

    vector<int> sorted_vec = input_vec;
    sort(sorted_vec.begin(), sorted_vec.end());

    for (int vi : sorted_vec)
    {
        if (ziplist.find(vi) == ziplist.end())
            ziplist.insert(make_pair(vi, zipnum++));
    }

    for (int vi : input_vec)
        ret.push_back(ziplist[vi]);

    return (ret);
}

void print(vector<int>zip)
{
    for (int vi : zip)
        cout << vi << ' ';

    return ;
}

int main()
{
    vector<int>v;
    int n;

    v = input(&n);
    print(zipped(v, n));

    return (0);
}
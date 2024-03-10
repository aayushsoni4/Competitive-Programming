#include <bits/stdc++.h>
#define int long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define rall(a) a.rbegin(), a.rend()
#define all(a) a.begin(), a.end()
#define arraysort(a, n) sort(a, a + n)
#define endl "\n"
#define inputarray(a, n) \
    f(i, 0, n) { cin >> a[i]; }
#define printarray(a, n)                \
    f(i, 0, n) { cout << a[i] << " "; } \
    cout << endl;
using namespace std;

int power(int a, int b, int p)
{
    if (a == 0)
        return 0;
    int res = 1;
    a %= p;
    while (b > 0)
    {
        if (b & 1)
            res = (1ll * res * a) % p;
        b >>= 1;
        a = (1ll * a * a) % p;
    }
    return res;
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a * b) / __gcd(a, b);
}

void solve()
{
    int n, m, p = 0, r;
    cin >> n;
    int a[n];
    inputarray(a, n);
    cin >> m;
    int b[m];
    inputarray(b, m);
    cin >> p;
    int c[p];
    inputarray(c, p);
    cin >> r;
    int q[r];
    inputarray(q, r);
    map<int, int> mp;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            f(k, 0, p)
            {
                mp[a[i] + b[j] + c[k]]++;
            }
        }
    }
    f(i, 0, r)
    {
        if (mp.find(q[i]) != mp.end())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases = 1;
    // cin >> testcases;
    while (testcases--)
    {
        solve();
    }
}
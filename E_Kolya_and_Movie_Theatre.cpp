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
    int n, m, ans = 0, p = 0, q, d;
    cin >> n >> m >> d;
    int a[n];
    inputarray(a, n);
    priority_queue<int, vector<int>, greater<int>> pq;
    int res = 0;
    vector<pair<int, int>> b;
    f(i, 0, n)
    {
        if (a[i] > 0)
            b.pb({a[i], i});
    }
    int sum = 0;
    f(i, 0, b.size())
    {
        sum += b[i].first;
        pq.push(b[i].first);
        int temp = 0;
        if (pq.size() > m)
        {
            temp = pq.top();
            pq.pop();
        }
        sum -= temp;
        res = max(res, sum - (d * (b[i].second+1)));
    }
    cout << res << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases = 1;
    cin >> testcases;
    while (testcases--)
    {
        solve();
    }
}
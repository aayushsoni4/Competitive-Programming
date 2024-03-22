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
const int mod = 1e9 + 7;

void dfs(int u, int p, vector<int> &sz, vector<int> adj[], int &mid, int &cnt)
{
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u, sz, adj, mid, cnt);
        sz[u] += sz[v];
    }
    if (sz[u] >= mid)
    {
        cnt++;
        sz[u] = 0;
    }
}

void solve()
{
    int n, k, x, y;
    cin >> n >> k;
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int low = 1, high = n, ans = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        vector<int> sz(n + 1,1);
        dfs(1, 0, sz, adj, mid, cnt);
        if (cnt >= k+1)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
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

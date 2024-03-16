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
int n, h, w;
vector<pair<int, int>> vp;
vector<vector<int>> grid;
vector<bool> used;

bool allCellsCovered()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (!grid[i][j])
                return false;
    return true;
}

bool canTile(int i, int j)
{
    if (i == h)
        return allCellsCovered();
    if (j == w)
        return canTile(i + 1, 0);
    if (grid[i][j])
        return canTile(i, j + 1);

    for (int k = 0; k < n; ++k)
    {
        if (used[k])
            continue;
        if (i + vp[k].first <= h && j + vp[k].second <= w)
        {
            bool ok = true;
            for (int x = 0; x < vp[k].first; ++x)
                for (int y = 0; y < vp[k].second; ++y)
                    if (grid[i + x][j + y])
                        ok = false;
            if (ok)
            {
                for (int x = 0; x < vp[k].first; ++x)
                    for (int y = 0; y < vp[k].second; ++y)
                        grid[i + x][j + y] = 1;
                used[k] = true;
                if (canTile(i, j + 1))
                    return true;
                for (int x = 0; x < vp[k].first; ++x)
                    for (int y = 0; y < vp[k].second; ++y)
                        grid[i + x][j + y] = 0;
                used[k] = false;
            }
        }
        if (i + vp[k].second <= h && j + vp[k].first <= w)
        {
            bool ok = true;
            for (int x = 0; x < vp[k].second; ++x)
                for (int y = 0; y < vp[k].first; ++y)
                    if (grid[i + x][j + y])
                        ok = false;
            if (ok)
            {
                for (int x = 0; x < vp[k].second; ++x)
                    for (int y = 0; y < vp[k].first; ++y)
                        grid[i + x][j + y] = 1;
                used[k] = true;
                if (canTile(i, j + 1))
                    return true;
                for (int x = 0; x < vp[k].second; ++x)
                    for (int y = 0; y < vp[k].first; ++y)
                        grid[i + x][j + y] = 0;
                used[k] = false;
            }
        }
    }

    return false;
}

void solve()
{
    cin >> n >> h >> w;
    vp.resize(n);
    used.resize(n, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> vp[i].first >> vp[i].second;
    }
    grid = vector<vector<int>>(h, vector<int>(w, 0));
    if (canTile(0, 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
    return 0;
}

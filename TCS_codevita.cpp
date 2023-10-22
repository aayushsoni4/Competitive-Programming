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
    int n, m, p = 0, q, r;
    cin >> n;
    cin >> r;
    string s;
    r--;
    cin >> s;
    if (r == 0)
    {
        cout << "" << endl;
        return;
    }
    vector<string> v;
    m = s.length();
    string temp = "";
    f(i, 0, m)
    {
        if (s[i] == ',')
        {
            v.push_back(temp);
            temp = "";
            continue;
        }
        temp += s[i];
    }
    v.push_back(temp);
    // printarray(v,v.size());
    vector<vector<int>> nCr(n + 1, vector<int>(n + 1, 0));
    f(i, 0, n + 1)
    {
        nCr[i][0] = 1;
        nCr[i][1] = i;
        // nCr[i][i]=0;
    }
    f(i, 2, n + 1)
    {
        f(j, 1, i + 1)
        {
            if (nCr[i - 1][j - 1] == 1e18 + 1 || nCr[i - 1][j] == 1e18 + 1)
            {
                nCr[i][j] = 1e18 + 1;
                continue;
            }
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
            if (nCr[i][j] > 1e18)
            {
                nCr[i][j] = 1e18 + 1;
            }
        }
    }

    int bit = 1;
    int sum = 0;
    f(i, 1, n + 1)
    {
        if (sum + nCr[n][i] >= r)
        {
            bit = i;
            break;
        }
        sum += nCr[n][i];
        bit = i;
    }
    f(i, 1, bit)
    {
        r -= nCr[n][i];
    }
    vector<int> ans;
    f(i, 1, n + 1)
    {
        int j = n - i;
        int temp = nCr[j][bit - 1];
        if (temp < r)
        {
            r -= temp;
        }
        else
        {
            ans.push_back(i);
            bit--;
        }
        if (bit == 0)
        {
            break;
        }
    }
    string res = "";
    f(i, 0, ans.size())
    {
        res += v[ans[i] - 1];
        res += ",";
    }
    res.pop_back();
    cout << res << endl;
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

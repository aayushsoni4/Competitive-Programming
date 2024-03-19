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

void solve()
{
    int n, m, p = 0, q;
    cin >> n >> m;
    int a[n];
    inputarray(a, n);
    int b[n];
    inputarray(b, n);
    vector<int> suf(n, 0);
    suf[n - 1] = b[n - 1];
    for(int i=n-2;i>=0;i--){
        suf[i] = suf[i+1] + b[i];
    }
    int ans = 1e18;
    int res = 0;
    m--;
    for(int i=n-1;i>=0;i--){
        if(i<=m){
            ans = min(ans,res+a[i]);
        }
        res += min(a[i], b[i]);
    }
    cout << ans << endl;
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
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
    cin >> n >> m >> p;
    int a[n];
    inputarray(a, n);
    int b[m];
    inputarray(b, m);
    int c[p];
    inputarray(c, p);
    sort(b, b + m);
    sort(c, c + p);

    int ans = 0;
    vector<int> diff;
    f(i, 0, n - 1)
    {
        ans = max(a[i + 1] - a[i], ans);
        diff.push_back(a[i + 1] - a[i]);
    }
    sort(diff.rbegin(), diff.rend());
    if (n > 2 && diff[0] == diff[1])
    {
        cout << diff[0] << endl;
        return;
    }
    int idx = 0;
    f(i, 0, n - 1)
    {
        if (a[i + 1] - a[i] == diff[0])
        {
            idx = i;
            break;
        }
    }
    int l = a[idx], r = a[idx + 1];
    f(i, 0, m)
    {
        int mid = (a[idx] + a[idx + 1]) / 2;
        int id = lower_bound(c,c+p,mid-b[i])-c;
        for(int j=max(0LL,id-1);j<=min(p-1,id+1);j++){
            if (c[j] + b[i] >= a[idx] and c[j] + b[i] <= a[idx + 1]){
                ans = min(ans,max(c[j]+b[i]-l, r-c[j]-b[i]));
            }
        }
    }
    if(n==2){
        cout << ans << endl;
        return;
    }
    cout << max(ans,diff[1]) << endl;
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
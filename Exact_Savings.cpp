#include <bits/stdc++.h>
#define int               long long
#define f(i,a,b)          for(int i=a;i<b;i++)
#define mp                make_pair
#define pb                push_back
#define rall(a)           a.rbegin(),a.rend()
#define all(a)            a.begin(),a.end()
#define arraysort(a,n)      sort(a,a+n)
#define endl              "\n"    
#define inputarray(a, n)  f(i, 0, n) { cin >> a[i]; }
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout << endl;
using namespace std;

int power(int a, int b, int p){
    if(a==0)
        return 0;
    int res=1;
    a%=p;
    while(b>0){
        if(b&1)
        res=(1ll*res*a)%p;
        b>>=1;
        a=(1ll*a*a)%p;
    }
    return res;
}

int lcm(int a, int b){
    if(a==0 || b==0)
        return 0;
    return (a*b)/__gcd(a,b);
}

void solve(){
    int n, m, p=0, q, z;
    cin >> n >> m >> z;
    int a[n];
    inputarray(a,n);
    vector<vector<int>>dp(n,vector<int>(m,0));
    int rem = (m - (z % m)) % m;

    int ans = 1e15;
    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= m; sum++) {
            dp[i][sum] = dp[i-1][sum];
            int j = (sum - (a[i]%m) + m) % m;
            dp[i][sum] = min(dp[i][sum], a[i] + dp[i-1][j]);
        }
    }

    if (dp[n][rem] == 1e15) cout << -1 << endl;
    else cout << (z + dp[n][rem]) / m << endl;
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases=1;
    cin >> testcases;
    while (testcases--){
        solve();
    }
}
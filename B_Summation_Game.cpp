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
    int n,k,x, m, p=0, q;
    cin >> n >> k >> x;
    int a[n];
    inputarray(a,n);
    int suff[n+1]={0};
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        suff[i]=suff[i+1]+a[i];
    }
    // printarray(suff,n+1);
    // n k x
    // 6 6 3
    // 1 4 2 3 5 6
    // 1 2 3 4 5 6 
    int ans = INT_MIN;
    for(int i=0;i<=k;i++){
        int alice_rm = n-i;
        int bob_rm = max(0LL,n-i-x);
        int sum_rm = suff[alice_rm];
        int sum_inverted = 0;
        int tot = 0;
        tot = suff[0] - suff[bob_rm];
        sum_inverted = suff[bob_rm]-sum_rm;
        ans = max(ans,tot-sum_inverted);
        // cout << i << " " << tot-sum_inverted << endl;
    }
    cout << ans << endl;



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
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
    int n, m, p=0, q;
    cin >> n;
    int a[n];
    inputarray(a,n);
    if(n==1){
        cout << 1 << endl;
        return;
    }
    vector<int>div;
    f(i,1,sqrt(n+2)){
        if(n%i==0){
            if(i*i==n)
                div.pb(i);
            else{
                div.pb(i);
                div.pb(n/i);
            }
        }
    }
    sort(all(div));
    int ans = 0;
    for(auto d: div){
        vector<vector<int>>vp(n/d,vector<int>(d));
        int g = 0;
        f(i,0,d){
            f(j,i+d,n){
                g = __gcd(abs(a[j]-a[j-d]),g);
            }
        }
        if(g!=1){
            ans++;
        }
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
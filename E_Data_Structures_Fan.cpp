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
    string s;
    cin >> s;
    cin >> q;
    int ans1[n+1] = {0};
    int ans0[n+1] = {0};
    int ans = 0;
    f(i,1,n+1){
        ans0[i]^=ans0[i-1];
        ans1[i]^=ans1[i-1];
        ans^=a[i-1];
        if(s[i-1]=='0'){
            ans0[i]^=a[i-1];
        }else{
            ans1[i]^=a[i-1];
        }
    }
    int res0 = ans0[n];
    while(q--){
        cin >> m;
        if(m==1){
            int l,r;
            cin >> l >> r;
            res0=res0^(ans0[r]^ans0[l-1]);
            res0=res0^(ans1[r]^ans1[l-1]);
        }
        else{
            int p;
            cin >> p;
            if(p==1){
                cout << (ans^res0) << " ";
            }
            else{
                cout << res0 << " ";
            }
        }
    }
    cout << endl;
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
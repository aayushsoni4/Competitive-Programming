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
    int n, m, N, L, p=0, q;
    cin >> n >> m;
    p=1;
    vector<int>ans;
    ans.pb(1);
    ans.pb(2);
    f(i,2,n){
        if(i+1==m || ans.back()+ans[ans.size()-2]>i+1){
            break;
        }
        ans.pb(i+1);
    }
    int left = n-ans.size();
    p=ans.back()+m+1;
    q = p+m+left+1;
    f(i,0,left-1){
        ans.pb(p);
        p++;
    }
    f(i,0,ans.size()){
        cout << ans[i] << " "; 
    }
    if(ans.size()!=n){
        cout << q;
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
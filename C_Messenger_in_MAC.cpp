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

bool comp(pair<int,int>&a, pair<int,int>&b){
    return a.second<b.second;
}

void solve(){
    int n, m, p=0, q;
    cin >> n >> m;
    vector<pair<int,int>>vp;
    f(i,0,n){
        int x,y;
        cin >> x >> y;
        vp.pb(mp(x,y));
    }
    sort(all(vp), comp);
    // f(i,0,n){
    //     cout << vp[i].first << " " << vp[i].second << endl;
    // }
    // cout << endl;
    int ans = 0;
    f(i,0,n){
        int a_sum = 0;
        int b_sum = 0;

        f(j,i,n){
            a_sum+=vp[j].first;
            if(j>i){
                b_sum+=abs(vp[j].second-vp[j-1].second);
            }
            // cout << i << " " << j << " -> " << a_sum+b_sum << endl;
            if(a_sum+b_sum<=m){
                ans = max(ans,j-i+1);
            }
            else{
                break;
            }
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
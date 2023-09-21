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
bool check(vector<vector<int>>&vp, int mid, int m){
    for(auto v: vp){
        if(v.size()<mid){
            continue;
        }
        else{
            int curr = 0;
            for(int j=0;j<mid;j++){
                curr+=v[j];
            }
            if(curr<=m){
                return true;
            }
            for(int j=mid;j<v.size();j++){
                curr+=v[j];
                curr-=v[j-mid];
                if(curr<=m){
                    return true;
                }
            }
        }
    }
    return false;
}
void solve(){
    int n, m, p=0, q;
    cin >> n >> m;
    int a[n];
    int h[n];
    inputarray(a,n);
    inputarray(h,n);
    vector<vector<int>>vp;
    int i = 0,j=0;
    while(i<n){
        vector<int>v;
        v.pb(a[j]);
        j++;
        while(j<n and h[j-1]%h[j]==0){
            v.pb(a[j]);
            j++;
        }
        i=j;
        vp.pb(v);
    }
    // for(auto i: vp){
    //     for(auto j: i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    int l = 1,r=n;
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(vp,mid,m)){
            ans = mid;
            l=mid+1;
        }
        else{
            r=mid-1;
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
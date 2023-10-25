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

int MOD=1e9+7;
const int MAXL=64;

int modInverse(int n,int p){
    return power(n, p - 2, p);
}

int powerm(int a,int b) {
    if(b==0) {
        return 1;
    }
    int curr=a,res=1;
    for(int i=0;i<MAXL;i++) {
        if((1LL<<i)&b) {
            res=(res*curr)%MOD;
        }
        curr=(curr*curr)%MOD;
    }
    return res;
}

vector<int>fac,inv;
int n1=0;

void facm(int x) { //precomputes factorials!
    n1=x;
    fac.resize(n1+1),inv.resize(n1+1); //till fac[n] and inv[n]
    fac[0]=1;
    for(int i=1;i<=n1;i++) {
        fac[i]=(fac[i-1]*i)%MOD;
    }
}

void preinv() { //precomputes inverse! Thanks Aman for that trick! :P
    inv[n1]=powerm(fac[n1],MOD-2);
    for(int i=n1-1;i>=0;i--) {
        inv[i]=(inv[i+1]*(i+1))%MOD;
    }
}

int choose(int a,int b) { //get nCr
    if(a<b) {
        return 0;
    }
    return ((fac[a]*inv[b])%MOD*inv[a-b])%MOD;
}

void dfs(int node, int& r, vector<int>adj[], vector<int>&vis){
    vis[node]=r;
    for(auto i: adj[node]){
        if(!vis[i]){
            dfs(i,r,adj,vis);
        }
    }
}

void solve(){
    int n, m, p=0, q,r=1;
    cin >> n >> m;
    vector<int>vis(n,0);
    vector<int>adj[n];
    f(i,0,m){
        cin >> p >> q;
        p--;
        q--;
        adj[p].pb(q);
        adj[q].pb(p);
    }
    f(i,0,n){
        if(!vis[i]){
            dfs(i,r,adj,vis);
            r++;
        }
    }
    int a[n];
    inputarray(a,n);
    vector<vector<int>>v(r);
    f(i,0,n){
        if(vis[i]!=0)
            v[vis[i]].pb(i);
    }
    int mod = 1e9+7;
    
    // for(auto i: v){
    //     for(auto j: i){
    //         cout << a[j] << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=0;i<n;i++){
    //     if(vis[i]==0){
    //         cout << a[i] << "\n";
    //     }
    // }


    int ans = 1;
    int left = n;
    for(auto i: v){
        map<int,int>mp;
        for(auto j: i){
            mp[a[j]]++;
        }
        for(auto t: mp){
            ans*=fac[t.second];
            ans%=mod;
        }
        ans*=choose(left,i.size());
        ans%=mod;
        left-=i.size();
    }
    f(i,0,n){
        if(vis[i]==-1){
            ans*=left;
            ans%=mod;
            left--;
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

    facm(300005);
    preinv();

    while (testcases--){
        solve();
    }
}
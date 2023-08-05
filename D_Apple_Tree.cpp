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
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout<<endl;
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

void dfs(int node, int par, int p, int indegree[], vector<int>adj[],vector<int>&vp){
    if(indegree[node]==1 and node!=1){
        p++;
    }
    for(auto i: adj[node]){
        if(i!=par){
            dfs(i,node,p,indegree,adj,vp);
            vp[node]+=vp[i];
        }
    }
    if(indegree[node]==1 and node!=1){
        vp[node]++;
    }
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    vector<int>adj[n+1];
    f(i,0,n-1){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }    
    cin >> q;
    vector<pair<int,int>>que;
    f(i,0,q){
        int x,y;
        cin >> x >> y;
        que.pb({x,y});
    }
    int indegree[n+1]={0};
    f(i,1,n+1){
        for(auto j: adj[i]){
            indegree[j]++;
        }
    }
    vector<int>vp(n+1,0);
    dfs(1,0,0,indegree,adj,vp);
    // f(i,0,n+1){
    //     cout << i << " ";
    // }
    // cout << endl;
    // printarray(indegree,n+1);
    // printarray(vp,n+1);
    // cout << endl;
    for(auto i: que){
        int x=i.first;
        int y=i.second;
        cout << vp[x]*vp[y] << endl;
    }

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
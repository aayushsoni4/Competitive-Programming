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

vector<vector<int>> adj;
vector<int> parent;
vector<int> dist;

void dfs(int node, int par){
    parent[node] = par;
    for(int child : adj[node]){
        if(child != par){
            dist[child] = dist[node] + 1;
            dfs(child, node);
        }
    }
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    adj.resize(n+1);
    parent.resize(n+1);
    dist.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[0] = 0;
    dfs(0, -1);
    int maxD = 0, maxNode = 0;
    for(int i = 0; i < n; i++){
        if(dist[i] > maxD){
            maxD = dist[i];
            maxNode = i;
        }
    }
    for(int i = 0; i < n; i++){
        dist[i] = 0;
        parent[i] = 0;
    }
    dfs(maxNode, -1);
    maxD = 0;
    for(int i = 0; i < n; i++){
        if(dist[i] > maxD){
            maxD = dist[i];
            maxNode = i;
        }
    }
    vector<int>diameter;
    while(maxNode != -1){
        diameter.push_back(maxNode);
        maxNode = parent[maxNode];
    }
    reverse(diameter.begin(), diameter.end());

    string s="";
    f(i,0,n){
        s+='?';
    }
    int r = 0, b = 0;
    for(int i=0;i<diameter.size()/2;i++){
        s[diameter[i]]='R';
        r++;
    }
    for(int i=diameter.size()/2;i<diameter.size();i++){
        s[diameter[i]]='B';
        b++;
    }
    f(i,0,n){
        if(s[i]=='?'){
            if(r<b){
                s[i]='R';
                r++;
            }
            else{
                s[i]='B';
                b++;
            }
        }
    }
    // f(i,0,n){
    //     cout << i+1 << " ";
    // }
    // cout << endl;
    
    // f(i,0,n){
    //     cout << s[i] << " ";
    // }
    // cout << endl;
    cout << s << endl;
    adj.clear();
    parent.clear();
    dist.clear();
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
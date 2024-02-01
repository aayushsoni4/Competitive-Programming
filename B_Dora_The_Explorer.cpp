#include <bits/stdc++.h>
#define f(i,a,b)          for(int i=a;i<b;i++)
#define mp                make_pair
#define pb                push_back
#define rall(a)           a.rbegin(),a.rend()
#define all(a)            a.begin(),a.end()
#define arraysort(a,n)      sort(a,a+n)
#define endl              "\n"    
#define inputarray(a, n)  f(i, 0, n) { cin >> a[i]; }
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout << endl;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

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

void dfs(int node, int par, vector<int>adj[], ordered_set &st, vector<int>&cost, int tok[]){
    int small = st.order_of_key(tok[node]);
    if(node==0){
        cost[node]=0;
    }
    else{
        cost[node]=cost[par]+small;
    }
    st.insert(tok[node]);
    for(auto i: adj[node]){
        if(i!=par){
            dfs(i,node,adj,st,cost,tok);
        }
    }
    st.erase(st.find(tok[node]));
}

void solve(){
    int n, m, p=0, q,cost, k;
    cin >> n >> k;
    int tok[n], tre[n];
    inputarray(tok,n);
    inputarray(tre,n);

    vector<int>cost(n,0);
    cost[0]=0;
    vector<int>adj[n];
    f(i,0,n-1){
        cin >> p >> q;
        adj[p-1].pb(q-1);
        adj[q-1].pb(p-1);
    }

    ordered_set st;
    dfs(0,-1,adj,st,cost,tok);
    printarray(cost,n);
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
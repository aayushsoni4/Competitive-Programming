#include <bits/stdc++.h>
#define int               long long
#define f(i,a,b)          for(int i=a;i<b;i++)
#define mp                make_pair
#define pb                push_back
#define rall(a)           a.rbegin(),a.rend()
#define all(a)            a.begin(),a.end()
#define arraysort(a)      sort(a,a+n)
#define endl              "\n"    
#define inputarray(a, n)  f(i, 0, n) { cin >> a[i]; }
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout<<endl;
using namespace std;


void dfs(int node, vector<int>adj[], vector<int>&v, vector<vector<int>>&ans){
    v.pb(node+1);
    int x=0;
    for(auto i: adj[node]){
        x++;
        dfs(i,adj,v,ans);
    }
    if(x==0){
        ans.pb(v);
        v.clear();
    }
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases=1;
    cin >> testcases;
    while (testcases--){
        int n, m, p=0, q;
        cin >> n;
        int a[n];
        inputarray(a,n);
        m=0;
        f(i,0,n){
            a[i]--;
            if(a[i]==i){
                m=i;
            }
        }
        vector<int>adj[n];
        f(i,0,n){
            if(a[i]!=i)
                adj[a[i]].pb(i);
        }

        vector<vector<int>>ans;
        vector<int>v;

        dfs(m,adj,v,ans);
        cout << ans.size() << endl;
        f(i,0,ans.size()){
            cout << ans[i].size() << endl;
            for(auto j: ans[i]){
                cout << j << " ";
            }
            cout << endl;
        }
        
    }
}
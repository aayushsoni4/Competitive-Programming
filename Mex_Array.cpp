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


void solve(){
    int n, m, p=0, q;
    cin >> n;
    int a[n];
    inputarray(a,n);
    map<int,int>mp;
    f(i,0,n){
        mp[a[i]]++;
    }
    sort(a,a+n);
    q=INT_MAX;
    vector<pair<int,int>>vp;
    f(i,0,a[n-1]+2){
        if(mp[i]<q){
            q=mp[i];
            vp.pb({i,mp[i]});
        }
    }

    for(auto i: vp){
        cout << i.first << " ";
    }
    cout << endl;

    for(auto i: vp){
        cout << i.second << " ";
    }
    cout << endl;
    cout << endl;

    vector<int>ans;
    q=0;
    int r=0;
    int sz=vp.size();
    for(int i=sz-1;i>0;i--){
        vp[i-1].second-=q;
        int p=vp[i-1].second;
        while(p>0){
            p--;
            ans.pb(vp[i].first);
        }
        q+=vp[i-1].second;
    }
    sz=ans.size();
    f(i,0,sz){
        r+=ans[i];
    }
    if(r<n){
        while(r<n){
            r++;
            ans.pb(0);
        }
    }
    sz=ans.size();
    cout << sz << endl;
    printarray(ans,sz);
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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define int             long long
#define all(a)          a.begin(),a.end()
#define endl            "\n"
#define fill(a,b) memset(a, b, sizeof(a))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;              
signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
while(t--){
    int i,j,x=0,y=0,p=0,n,q=-1,u=0,v=0,k,c=0,m;
    cin>>n;
    vector<vector<int>>lb;
    for(i=0;i<n;i++){
        vector<int>v2(4);
        for(j=0;j<4;j++) cin>>v2[j];
        sort(all(v2));
        lb.push_back({v2[0],v2[2]});
    }
    sort(all(lb));
    x=-1;
    y=-1;
    vector<pair<int,int>>vp;
    for(i=0;i<n;i++){
        if(x==-1){
            x=lb[i][0];
            y=lb[i][1];
        }
        else{
            if(lb[i][0]<=y) y=max(y,lb[i][1]);
            else{
                vp.push_back({x,y});
                x=lb[i][0];
                y=lb[i][1];
            }
        }
    }
    vp.push_back({x,y});
    int n1=vp.size();
    int a[n1];
    for(i=0;i<n1;i++){
        a[i]=vp[i].first;
    }
    cin>>q;
    while(q--){
        cin>>x;
        int ans=x;
        p=upper_bound(a,a+n1,x)-a;
        p--;
        if(p>=0)
        ans=max(ans,vp[p].second);
        cout<<ans<<" ";
    }
    cout<<endl;



    }
}
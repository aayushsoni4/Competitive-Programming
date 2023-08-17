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

void solve(){
    int n, m, p=0, q;
    cin >> n;
    vector<vector<int>>a;
    f(i,0,n){
        cin >> q;
        vector<int>temp;
        f(j,0,q){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        sort(all(temp));
        a.pb(temp);
    }    
    sort(all(a));
    if(n==1){
        cout << a[0][0] << endl;
        return;
    }
    vector<pair<int,int>>vp;
    f(i,0,n){
        int  p=0;
        for(auto j: a[i]){
            vp.push_back({j,i}); 
            p++;
            if(p==2){
                break;
            }
        }
    }

    // for(auto i: vp){
    //     cout << i.first << " ";
    // }
    // cout << endl;
    // cout << endl;

    sort(all(vp));
    int res = 0;
    vector<int>vis(n,0);
    p=0;
    for(int i=vp.size()-1;i>=0;i--){
        if(p==n-1){
            res+=vp[0].first;
            break;
        }
        if(!vis[vp[i].second]){
            res+=vp[i].first;
            vis[vp[i].second]=1;
            p++;
        }
    }
    cout << res << endl;
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
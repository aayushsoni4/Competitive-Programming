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

bool mycomp(pair<int,int>&a, pair<int,int>&b){
    return a.second>b.second;
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    vector<set<int>>v;
    map<int,vector<int>>mp;
    f(i,0,n){
        int k;
        cin >> k;
        set<int>s;
        f(i,0,k){
            int x;
            cin >> x;
            s.insert(x);
        }
        for(auto r: s){
            mp[r].push_back(i);
        }
        v.pb(s);
    }    
    if(n==1){
        cout << 0 << endl;
        return;
    }
    vector<pair<int,int>>vp;
    for(auto i: mp){
        vp.push_back({i.first,i.second.size()});
    }
    sort(vp.begin(),vp.end(),mycomp);
    int ans=0;
    set<int>s;
    // for(auto i: vp){
    //     cout << i.first << " ";
    // }
    // cout << endl;
    // cout << endl;
    f(i,0,n){
        for(auto j: mp[vp[i].first]){
            for(auto ele: v[j]){
                s.insert(ele);
            }
            if(s.size()!=mp.size())
                ans = max(ans,(int)s.size());
            else
                break;
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
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
#define MOD 1000000007

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

bool isprime(int n){
    if(n==1)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void solve(){
    int n, m, p=0, q;
    cin >> n >> m;
    int a[n];
    inputarray(a,n);
    if(!isprime(m)){
        cout << 0 << endl;
        return;
    }
    vector<int>prime;
    f(i,2,m+1){
        if(isprime(i)){
            prime.pb(i);
        }
    }
    vector<int>v;
    map<int,int>temp;
    f(i,0,n){
        if(a[i]%m==0){
            v.push_back(a[i]);
        }
    }
    if(v.size()==0){
        cout << 0 << endl;
        return;
    }
    map<int,vector<int>, greater<int>>mp;
    for(auto i: v){
        for(auto pr: prime){
            if(i%pr==0){
                mp[pr].push_back(i);
                break;
            }
        }
    }
    int ans = 0;
    int ele = 0;
    for(auto i: mp[m]){
        ans+=power(2,ele,MOD);
        ele++;
    }
    int t = ele;
    map<int,vector<int>>st;
    mp.erase(m);
    for(auto i: mp){
        int res = 0;
        for(auto j: i.second){
            cout << j << " ->";
            res+=(power(2,ele,MOD)-1+MOD)%MOD;

            int ct = 0;
            for(auto k: st){
                if(j%k.first==0){
                    ct+=k.second.size();
                }
            }
            ct =(power(2,ct,MOD)-1+MOD)%MOD;
            res-=ct;
            res+=MOD;
            res%=MOD;

            ele++;
            st[i.first].pb(j);
            cout << res << endl;
        }
        ans+=res;
        ans%=MOD;
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
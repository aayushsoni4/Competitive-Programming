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

void solve(){
    int n, m, p=0, q;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int,int>>vp(m);
    f(i,0,m){
        cin >> vp[i].first >> vp[i].second;
        vp[i].first--;
        vp[i].second--;
    }
    set<pair<int,int>>st;
    vector<int>zero(n,0), one(n,0);
    f(i,1,n){
        if(s[i]=='0'){
            zero[i]=i;
        }
        else{
            zero[i]=zero[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]=='1'){
            one[i]=n-i-1;
        }
        else{
            one[i]=one[i+1];
        }
    }
    // printarray(zero,n);
    // printarray(one,n);
    f(i,0,m){
        int l=vp[i].first, r=vp[i].second;
        int z = zero[r];        
        int o = n-one[l];
        // cout << z << " " << o << endl;
        if(z<o || l==r){
            st.insert({-1,-1});
        }
        else{
            st.insert({o,z});
        }        
    }
    cout << st.size() << endl;
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
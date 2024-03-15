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
    cin >> n;
    int a[n];
    inputarray(a,n);
    vector<int>v;
    string te = to_string(a[0]);
    if(is_sorted(all(te))){
        for(auto t: te){
            v.pb(t-'0');
        }
    }
    else{
        v.pb(a[0]);
    }
    f(i,1,n){
        if(a[i]<10){
            v.pb(a[i]);
        }
        else{
            string s = to_string(a[i]);
            if(is_sorted(all(s)) && s[0]-'0'>=v.back()){
                for(auto t: s){
                    v.pb(t-'0');
                }
            }
            else{
                v.pb(a[i]);
            }
        }
        if(!is_sorted(all(v))){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
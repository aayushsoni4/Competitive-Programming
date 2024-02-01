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

int MOD=1e9+7;
int MAXL=64;

int powerm(int a,int b) {
    if(b==0) {
        return 1;
    }
    int curr=a,res=1;
    for(int i=0;i<MAXL;i++) {
        if((1LL<<i)&b) {
            res=(res*curr)%MOD;
        }
        curr=(curr*curr)%MOD;
    }
    return res;
}


int modInverse(int n,int p){
    return powerm(n, p - 2);
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    p = powerm(10,n);
    q = p*modInverse(3LL,MOD);
    cout << q%MOD << endl;

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
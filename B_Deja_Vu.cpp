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
    cin >> n >> q;
    int a[n],x[q];
    inputarray(a,n);
    inputarray(x,q);

    vector<int>r1;
    int r = x[0];
    r1.pb(x[0]);
    f(i,1,q){
        if(x[i]<r){
            r1.push_back(x[i]);
            r = x[i];
        }
    }
    q = r1.size();
    f(i,0,q){
        f(j,0,n){
            if(a[j]%(1LL<<r1[i])==0){
                a[j]+=(1LL<<(r1[i]-1));
            }
        }
    }
    printarray(a,n);


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
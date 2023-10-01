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
    int n, m, p=0,k, q;
    cin >> n >> k;
    p = n/2;
    int a[n];
    if((p%2==1 and k%2==0) || k<(3*p)){
        cout << -1 << endl;
        return;
    }
    f(i,0,p){
        a[i]=1;
        k--;
    }
    if(k%2==1){
        cout << -1 << endl;
    }
    q=k/p;
    m=k%p;
    int left = 0;
    if(q%2==1){
        q--;
        left=p;
    }
    if(left%2==1){
        cout << -1 << endl;
        return;
    }
    f(i,p,n){
        a[i]=q;
    }
    a[n-1]+=left;
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
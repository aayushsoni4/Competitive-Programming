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
    int n, m;
    // int p=0, q;
    cin >> n >> m;
    // vector<pair<int,int>>vp;
    int prev=0;
    // f(i,1000000,5000000){
    // int i = ((pow(3,6)*pow(11,6)));
    int l = 1e16,r=1e17;
    while(l<=r){
        int i = l+(r-l)/2;
        int p = 0;
        int x = i;
        while(x>1){
            x/=2;
            p++;
        }
        int q = 0;
        x = i;
        while(x>p-1){
            x/=p;
            q++;
        }
        cout << i << " " << q << endl;
        if(q==1){
            prev = i;
            r=i-1;
        }
        else{
            l=i+1;
        }
        // if(q!=prev){
        //     cout << i << " " << q << endl;
        //     prev = q;
        // }
    }    
    cout << prev << endl;
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
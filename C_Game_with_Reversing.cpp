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

int check(string& s, string& w, int n){
    int ans=0;
    f(i,0,n){
        if(s[i]!=w[i]){
            ans++;
        }
    }
    return ans;
}

void solve(){
    int n, m, p=0, q=0;
    string s,w;
    cin >> n >> s >> w;
    
    if(s==w){
        cout << 0 << endl;
        return;
    }
    
    p=check(s,w,n);
    reverse(all(s));
    q=check(s,w,n);
    reverse(all(s));
    int ans=0;
    if(p==q){
        cout << 2*p-1 << endl;
        return;
    }
    if(p==1){
        cout << 1 << endl;
        return;
    }

    if(q<=1){
        cout << 2 << endl;
        return;
    }
    // cout << p << endl;
    // cout << q << endl;
    // cout << endl;
    if(p>q){
        if(q%2==0)
            cout << 2*q-1 << endl;
        else
            cout << 2*q << endl;
    }
    else{
        if(p%2==1)
            cout << 2*p-1 << endl;
        else
            cout << 2*p << endl;
    }
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
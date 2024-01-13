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
    int a1,a3,a2;
    a1 = INT_MIN;
    a2 = INT_MAX;
    vector<int>v;
    f(i,0,n){
        int a,x;
        cin >> a >> x;
        if(a==1){
            a1 = max(a1,x);
        }
        else if(a==2){
            a2 = min(a2,x);
        }
        else{
            v.push_back(x);
        }
    }    
    // cout << a1 << " " << a2 << endl;
    if(a1>a2){
        cout << 0 << endl;
    }
    else{
        int ans = a2-a1+1;
        f(i,0,v.size()){
            if(v[i]>=a1 && v[i]<=a2){
                ans--;
            }
        }
        cout << ans << endl;
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
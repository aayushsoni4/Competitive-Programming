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
    int a[n];
    inputarray(a,n);
    int ev = 0, od = 0;
    f(i,0,n){
        if(a[i]%2==0){
            ev++;
        }
        else{
            od++;
        }
    }
    int mod = 1e9+7;
    int od_space = n/2;
    int ev_space = n-od_space;
    if(m==0){
        if(n==od || n==ev){
            int ans = 1;
            f(i,1,n+1){
                ans*=i;
                ans%=mod;
            }
            cout << ans << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        if(ev==ev_space || od==od_space){
            int ans = 1;
            f(i,1,ev_space){
                ans*=i;
                ans%=mod;
            }
            int temp = ans;
            ans=1;
            f(i,1,od_space){
                ans*=i;
                ans%=mod;
            }
            cout << ans+temp << endl;
        }
        else if(ev==od_space || od==ev_space){
            int ans = 1;
            f(i,1,ev_space){
                ans*=i;
                ans%=mod;
            }
            int temp = ans;
            ans=1;
            f(i,1,od_space){
                ans*=i;
                ans%=mod;
            }
            cout << ans+temp << endl;
        }
        else{
            cout << 0 << endl;
        }
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
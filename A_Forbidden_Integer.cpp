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

void solve(){
    int k,n, m, p=0, q;
    cin >> n >> m >> k;
    if(m==1){
        cout << "NO" << endl;
        return;
    }
    if(k!=1){
        cout << "YES" << endl;
        cout << n << endl;
        f(i,0,n){
            cout << 1 << " ";
        }
        cout << endl;
    }   
    else{
        if(n%2==0){
            cout << "YES" << endl;
            cout << n/2 << endl;
            f(i,0,n/2){
                cout << 2 << " ";
            }
            cout << endl;
            return;
        }
        if(m==2){
            if(n%2==0){
                cout << "YES" << endl;
                cout << n/2 << endl;
                f(i,0,n/2){
                    cout << 2 << " ";
                }
                cout << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "YES" << endl;
            if(n%2==1){
                cout << 1+(n-3)/2 << endl;
                f(i,0,(n/2)-1){
                    cout << 2 << " ";
                }
                cout << 3 << endl;
            }
            else{
                cout << 2+(n-6)/2 << endl;
                f(i,0,(n-6)/2){
                    cout << 2 << " ";
                }
                cout << 3 << " " << 3 << endl;
            }
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
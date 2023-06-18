#include <bits/stdc++.h>
// #define int               long long
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
    int n, m, p=0, q;
    cin >> n;
    int l=0,r=n-1;
    while(l<=r){
        int a,b;
        int mid = (l+r)/2;
        if(l==r){
            break;
        }
        if(l+1!=mid+1){
            cout << "? " << l+1 << " " << mid+1 << endl;
        }
        else{
            cout << "? " << l+1 << " " << mid+2 << endl;
        }
        cin >> a;
        if(mid+2!=r+1){
            cout << "? " << mid+2 << " " << r+1 << endl;
        }
        else{
            cout << "? " << mid+1 << " " << r+1 << endl;
        }
        cin >> b;
        if(a>b){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }    
    cout << "! " << l+1 << endl;
}

signed main (){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int testcases=1;
    // cin >> testcases;
    while (testcases--){
        solve();
    }
}
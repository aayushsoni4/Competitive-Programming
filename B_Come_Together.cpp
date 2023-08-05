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

void solve(){
    int n, m, p=0, q;
    int a1,a2,a3,b1,b2,b3;
    cin >> a1 >> b1;    
    cin >> a2 >> b2;    
    cin >> a3 >> b3;    
    int xa = a1-a2;
    int xb = a1-a3;
    int ya = b1-b2;
    int yb = b1-b3;
    
    int ans=1;
    if(xa*xb>=0){
        ans+=abs(min(abs(a2-a1),abs(a3-a1)));
    }
    if(ya*yb>=0){
        ans+=abs(min(abs(b2-b1),abs(b3-b1)));
    }
    cout << ans << endl;
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
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
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout << endl;
using namespace std;
void solve(){
    int n, m, p=0, q;
    cin >> n;
    set<int>s;
    f(i,0,n){
        int x;
        cin >> x;
        s.insert(x);
    }
    for(auto i: s){
        if(i==p){
            p++;
        }
        else{
            break;
        }
    }
    q = 2*n+1;
    int lastRm = 0;
    while(q--){
        cout << p << endl;
        int y;
        cin >> y;
        p = y;
        if(y==-2 || y==-1){
            return;
        }
        s.erase(y);
    }
}

signed main (){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int testcases=1;
    cin >> testcases;
    while (testcases--){
        solve();
    }
}
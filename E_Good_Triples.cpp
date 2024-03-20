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

int digsum(int n){
    int s = 0;
    while(n!=0){
        s+=n%10;
        n/=10;
    }
    return s;
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    int ans = 1;
    string s = to_string(n);
    for(auto st : s){
        p=0;
        f(i,0,10){
            f(j,0,10){
                if((st-'0')-i-j>=0){
                    p++;
                }
            }
        }
        ans*=p;
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
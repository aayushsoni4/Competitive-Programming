#include <bits/stdc++.h>
#define int             long long
#define f(i,a,b)        for(int i=a;i<b;i++)
#define pb              push_back
#define all(a)          a.begin(),a.end()
#define arraysort(a)    sort(a,a+n)
#define endl            "\n"
#define inputarray(a,n) f(i,0,n){cin >> a[i];}
#define printarray(a,n) f(i,0,n){cout << a[i] << " ";}cout << endl;
using namespace std;

int func(int l, int x, int s){
    int st = min(s,max(1LL,(s%l)));
    int en = max(s,x-(x-s)%l);
    int tot = (en - st)/l;
    tot++;
    return tot;
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, m , x , y, l;
        cin >> n >> m >> x >> y >> l;
        cout << func(l,n,x)*func(l,m,y) << endl;


    }
}

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

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>>v1,v2,v3;
    f(i,0,n){
        int x;
        cin >> x;
        v1.push_back({x,i});
    }
    f(i,0,n){
        int x;
        cin >> x;
        v2.push_back({x,i});
    }
    f(i,0,n){
        int x;
        cin >> x;
        v3.push_back({x,i});
    }
    sort(all(v1));
    sort(all(v2));
    sort(all(v3));
    
    reverse(all(v1));
    reverse(all(v2));
    reverse(all(v3));

    int ans = 0;
    f(i,0,3){
        f(j,0,3){
            f(k,0,3){
                if(v1[i].second!=v2[j].second && v2[j].second!=v3[k].second && v1[i].second!=v3[k].second)
                    ans = max(ans, v1[i].first+v2[j].first+v3[k].first);
            }
        }
    }
    cout << ans << endl;
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases = 1;
    cin >> testcases;
    while (testcases--){
        solve();
    }
}

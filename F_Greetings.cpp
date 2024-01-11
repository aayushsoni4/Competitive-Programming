#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;




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
    ordered_multiset o_set; 
    vector<pair<int,int>>vp;
    f(i,0,n){
        cin >> p >> q;
        vp.pb({p,q});
    }    
    sort(all(vp));
    f(i,0,n){
        o_set.insert(vp[i].second);
    }
    int ans = 0;
    f(i,0,n){
        ans += (o_set.order_of_key(vp[i].second));
        auto it = o_set.find_by_order(o_set.order_of_key(vp[i].second));
        o_set.erase(it);
        // cout << vp[i].second << " " << (o_set.order_of_key(vp[i].second)) << "\n";
        // for(auto i: o_set){
            // cout << i << " ";
        // }cout << endl;
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
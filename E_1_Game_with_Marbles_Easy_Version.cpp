#include <bits/stdc++.h>
#define int long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define inputarray(a, n) f(i,0,n) { cin >> a[i]; }
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout << endl;
using namespace std;

bool comp(pair<int,int>a, pair<int,int>b){
    return a.first+a.second>b.second+b.first;
}

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    inputarray(a, n);
    inputarray(b, n);
    vector<pair<int,int>>vp;
    f(i,0,n){
        vp.push_back({a[i],b[i]});
    }
    sort(vp.begin(),vp.end(),comp);

    // set<pair<int, int>, greater<pair<int, int>>> st1, st2;
    // map<int, int> mp1, mp2;
    // f(i, 0, n) {
    //     st1.insert({a[i], i});
    //     st2.insert({b[i], i});
    //     mp1[i] = a[i];
    //     mp2[i] = b[i];
    // }


    
    int chance = 0;
    // while (!st1.empty() && !st2.empty()) {
    //     if (chance == 0) {
    //         int idx = (*st2.begin()).second;
    //         st2.erase(st2.begin());
    //         a[idx]--;
    //         b[idx] = 0;
    //         mp2[idx] = 0;
    //         st1.erase(st1.find({mp1[idx], idx}));
    //         mp1[idx]--;
    //         chance = 1;
    //     }
    //     else {
    //         int idx = (*st1.begin()).second;
    //         st1.erase(st1.begin());
    //         b[idx]--;
    //         a[idx] = 0;
    //         mp1[idx] = 0;
    //         st2.erase(st2.find({mp2[idx], idx}));
    //         mp2[idx]--;
    //         chance = 0;
    //     }
    // }

    // printarray(a,n);
    // printarray(b,n);
    
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!chance){
            ans+=vp[i].first-1;
        }
        else{
            ans-=vp[i].second-1;
        }
        chance^=1;
    }
    
    cout << ans << endl;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases = 1;
    cin >> testcases;
    while (testcases--) {
        solve();
    }
}

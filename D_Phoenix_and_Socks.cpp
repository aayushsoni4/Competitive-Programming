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
    int n, m, p=0,l, r, q, ans=0;
    cin >> n >> l >> r;
    vector<int>left;
    vector<int>right;
    map<int,int>mp;
    f(i,0,l){
        int x;
        cin >> x;
        mp[x]++;
    }
    f(i,0,r){
        int x;
        cin >> x;
        if(mp[x]==0){
            right.pb(x);
        }
        else{
            mp[x]--;
        }
    }
    for(auto i: mp){
        if(i.second>1){
            ans+=i.second/2;
            mp[i.first]=i.second%2;
        }
    }
    for(auto i: mp){
        int p=i.second;
        while(p--){
            left.pb(i.first);
        }
    }
    mp.clear();
    for(auto i: right){
        mp[i]++;
        if(mp[i]==2){
            mp.erase(i);
            ans++;
        }
    }
    right.clear();
    for(auto i: mp){
        int p=i.second;
        while(p--){
            right.pb(i.first);
        }
    }
    sort(all(left));
    sort(all(right));

    printarray(left,left.size());
    printarray(right,right.size());
    
    cout << ans+max(left.size(),right.size()) << endl;
    cout << endl;
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
#include <bits/stdc++.h>
#define int long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define pb push_back
#define rall(a) a.rbegin(),a.rend()
#define all(a) a.begin(),a.end()
#define arraysort(a,n) sort(a,a+n)
#define endl "\n"    
#define inputarray(a, n) f(i, 0, n) { cin >> a[i]; }
#define printarray(a,n) f(i, 0, n) { cout << a[i] << " "; } cout << endl;
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n],b[m];
    inputarray(a,n);
    inputarray(b,m);
    map<int,int>freq_a;
    map<int,int>freq_b;
    f(i,0,m){
        freq_b[b[i]]++;
    }
    int simi = 0;
    f(i,0,min(n,m)){
        freq_a[a[i]]++;
        if(freq_b.find(a[i])!=freq_b.end() && freq_a[a[i]]<=freq_b[a[i]]){
            simi++;
        }
    }
    int ans = 0;
    if(simi>=k){
        ans++;
    }
    f(i,min(n,m),n){
        freq_a[a[i]]++;
        if(freq_b.find(a[i])!=freq_b.end() && freq_a[a[i]]<=freq_b[a[i]]){
            simi++;
        }
        freq_a[a[i-m]]--;
        if(freq_b.find(a[i-m])!=freq_b.end() && freq_a[a[i-m]]<freq_b[a[i-m]]){
            simi--;
        }
        if(simi>=k){
            ans++;
        }
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

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
    cin >> n >> m;
    int a[n+1];
    f(i,0,n){
        cin >> a[i+1];
    }
    int l = 1, r = n+1;
    int idx = -1;
    f(i,0,n){
        if(a[i+1]==m){
            idx = i+1;
        }
    }
    vector<int>v;
    int f = 0;
    while(true){
        int mid = (l+r)/2;
        v.pb(mid);
        if(r-l<=1){
            break;
        }
        // cout << l << " " << r << endl;
        if(mid==idx){
            f = 1;
        }
        if(a[mid]<=m){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if(a[v.back()]==m){
        cout << 0 << endl;
        return;
    }
    if(f==0){
        cout << 1 << endl;
        cout << min(idx,v.back()) << " " << max(idx,v.back()) << endl;
        return;
    }
    // cout << l << endl;
    map<int,int>mp;
    f(i,0,v.size()){
        if(a[v[i]]<m)
            mp[a[v[i]]] = 1;
    }
    int temp = 0, id1=-1;
    f(i,1,n+1){
        if(mp[i]==0){
            temp = i;
            break;
        }
    }
    f(i,1,n+1){
        if(a[i]==temp){
            id1 = i;
            break;
        }
    }
    cout << 2 << endl;
    cout << id1 << " " << idx << endl;
    cout << id1 << " " << v.back() << endl; 



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
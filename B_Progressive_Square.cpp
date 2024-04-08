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
    cin >> m >> p >> q;
    n = m*m;
    int a[n];
    inputarray(a,n);
    sort(a,a+n);
    map<int,int>mp;
    f(i,0,n){
        mp[a[i]]++;
    }
    vector<vector<int>>v(m,vector<int>(m));
    v[0][0] = a[0];
    f(i,1,m){
        if(mp.find(v[0][i-1]+q)!=mp.end()){
            mp[v[0][i-1]+q]--;
            if(mp[v[0][i-1]+q]==0){
                mp.erase(v[0][i-1]+q);
            }
            v[0][i] = v[0][i-1]+q;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    f(i,1,m){
        if(mp.find(v[i-1][0]+p)!=mp.end()){
            mp[v[i-1][0]+p]--;
            if(mp[v[i-1][0]+p]==0){
                mp.erase(v[i-1][0]+p);
            }
            v[i][0] = v[i-1][0]+p;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    f(i,1,m){
        f(j,1,m){
            if(mp.find(v[i-1][j]+p)!=mp.end() && mp.find(v[i][j-1]+q)!=mp.end() && v[i-1][j]+p == v[i][j-1]+q){
                mp[v[i-1][j]+p]--;
                if(mp[v[i-1][j]+p]==0){
                    mp.erase(v[i-1][j]+p);
                }
                v[i][j] = v[i-1][j]+p;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    // f(i,0,m){
    //     f(j,0,m){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "YES" << endl;
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

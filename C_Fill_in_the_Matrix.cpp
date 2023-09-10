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
    int n, m, p=0, q=1;
    cin >> n >> m;
    int a[m];
    iota(a,a+m,0);
    vector<vector<int>>ans(n,vector<int>(m));
    for(int i=0;i<n;i++){
        p=i+1;
        if((i+1)%m==0){
            p+=q;
        }
        f(j,0,m){
            ans[i][j] = a[(j+p)%m];
        }
    }
    set<int>res;
    f(j,0,m){
        set<int>st;
        f(i,0,n){
            st.insert(ans[i][j]);
        }
        int p=0;
        for(auto i: st){
            if(i==p){
                p++;
            }
            else{
                break;
            }
        }
        res.insert(p);
    }
    p=0;
    for(auto i: res){
        if(i==p){
            p++;
        }
        else{
            break;
        }
    }
    cout << p << endl;

    f(i,0,n){
        f(j,0,m){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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
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
    cin >> n;
    int a[n];
    inputarray(a,n);
    vector<vector<int>>v(n,vector<int>(31,0));
    f(i,0,n){
        f(j,0,31){
            if((a[i]&(1<<j))){
                v[i][j]=1;
            }
        }
    }
    f(i,0,n){
        f(j,0,31){
            if(i>0)
                v[i][j]+=v[i-1][j];
        }
    }

    // f(j,0,5){
    //     f(i,0,n){
    //     // cout << a[i] << " -> ";
    //     cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int z = 0;
    cin >> q;
    while(q--){
        int l, r, k;
        cin >> l >> k;
        l--;
        int fix = l;
        r = n-1;
        int ans=-1;
        while(l<=r){
            int mid = (l+r)/2;
            int flag=0;
            int maxi = 0;
            f(i,0,31){
                int x = v[mid][i];
                if(fix>0)
                    x-=v[fix-1][i];
                if(x==(mid-fix+1)){
                    maxi+=(1<<i);
                }
            }
            if(maxi>=k){
                ans = mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(ans!=-1)
            cout << ans+1 << " ";
        else
            cout << ans << " ";
    }
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
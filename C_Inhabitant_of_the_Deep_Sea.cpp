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
    int n, m, p=0, q, k;
    cin >> n >> k;
    int a[n];
    inputarray(a,n);
    int pref[n], suff[n];
    pref[0] = a[0];
    suff[n-1] = a[n-1];
    f(i,1,n){
        pref[i] = pref[i-1] + a[i];
    }
    for(int i=n-2;i>=0;i--){
        suff[i] = suff[i+1] + a[i];
    }
    if(pref[n-1]<=k){
        cout << n << endl;
        return;
    }
    int front = (k+1)/2;
    int back = (k)/2;
    int ans = 0;
    // printarray(pref, n);
    // printarray(suff, n);
    f(i,0,n){
        int l = 0, r = i;
        int res1 = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(pref[mid]<=front){
                res1 = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        l = i+1, r = n-1;
        int res2 = n;
        while(l<=r){
            int mid = (l+r)/2;
            if(suff[mid]<=back){
                res2 = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        int left = 0;
        if(res1!=-1 && res2!=n){
            left = front-pref[res1]+back-suff[res2];
        }
        if(left>0 and res2==res1+1){
            if(res2==i+1 and left>=a[res1]){
                ans = max(ans, n);
            }
            else if(res1==i and left>=a[res2]){
                ans = max(ans, n);
            }
            else{
                ans = max(ans, n-1);
            }
        }
        else{
            ans = max(ans, res1+1+(n-res2));
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
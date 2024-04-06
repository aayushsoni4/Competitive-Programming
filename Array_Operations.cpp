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
    int a[n];
    inputarray(a,n);
    int l = 1, r = n;
    int ans = 1;
    while(l<=r){
        int mid = (l+r)/2;
        priority_queue<int>divi, less, great;
        int p = 0;
        f(i,0,n){
            if(a[i]%m==0){
                if(a[i]>=mid){
                    p++;
                }
                divi.push(a[i]);
                continue;
            }
            if(a[i]<mid)
                less.push(a[i]);
            else
                great.push(a[i]);
        }
        if(p+great.size()>=mid){
            ans = mid;
            l=mid+1;
            continue;
        }
        while(!divi.empty()){
            int r = divi.top();
            divi.pop();
            if(r%m==0 and r/m>=mid and !less.empty()){
                r/=m;
                int te = less.top();
                less.pop();
                te*=m;
                if(te<mid){
                    less.push(te);
                }
                else{
                    great.push(te);
                }
            }
            else{
                p--;
                great.push(r);
            }
        }
        while(!divi.empty() and divi.top()>=mid){
            divi.pop();
        }
        while(!divi.empty()){
            int r = divi.top();
            divi.pop();
            while(r%m==0 and !less.empty()){
                r/=m;
                int te = less.top();
                less.pop();
                te*=m;
                if(te<mid){
                    less.push(te);
                }
                else{
                    great.push(te);
                }
            }
        }
        if(p+great.size()>=mid){
            ans = mid;
            l=mid+1;
        }
        else{
            r=mid-1;
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
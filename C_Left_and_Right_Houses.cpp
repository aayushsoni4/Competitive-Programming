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
    string s;
    cin >> s;
    vector<int>left(n+1,0), right(n+1,0);    
    f(i,1,n+1){
        if(s[i-1]=='0'){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = left[i-1];
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            right[i] = (i==n-1 ? 0 : right[i+1]) + 1;
        }
        else{
            right[i] = (i==n-1 ? 0 : right[i+1]);
        }
    }
    int ans = INT_MAX;
    int mini = INT_MAX;
    f(i,0,n+1){
        int l = i;
        int r = n-i;
        int want_left = left[i];
        int want_right = right[i];
        int ok_left = (l+1)/2;
        int ok_right = (r+1)/2;
        if(ok_left<=want_left and ok_right<=want_right){
            if(abs((n-2*i)/2)<mini){
                mini = abs((n-2*i)/2);
                ans = i;
            }
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
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
    string s,t;
    cin >> s >> t;
    string ans = "";
    ans+=s[0];
    int i=1,j=0;
    while(i<n){
        if(s[i]=='0' || (s[i]=='1' && t[j]=='1')){
            ans+=s[i];
            i++;
            j++;
        }
        else{
            while(j<n and i<n){
                if(s[i]=='1' && t[j]=='0'){
                    ans+=t[j];
                    j++;
                    break;
                }
                else{
                    ans+=s[i];
                    i++;
                }
            }
            break;
        }
    }
    while(j<n){
        ans+=t[j];
        j++;
    }
    vector<string>grid;
    grid.pb(s);
    grid.pb(t);
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
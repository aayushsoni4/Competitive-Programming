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
    vector<string>v;
    map<char,int>mp;
    mp['a'] = 1;
    mp['e'] = 1;
    mp['b'] = 0;
    mp['c'] = 0;
    mp['d'] = 0;
    for(int i=n-1;i>=0;i--){
        string temp="";
        if(mp[s[i]]==1){
            temp = s[i-1];
            temp+=s[i];
            v.pb(temp);
            i--;
        }
        else{
            temp = s[i-2];
            temp += s[i-1];
            temp += s[i];
            v.pb(temp);
            i-=2;
        }
    }    
    reverse(all(v));
    string ans = "";
    for(int i=0;i<v.size();i++){
        ans+=v[i];
        ans+='.';
    }
    ans = ans.substr(0,ans.size()-1);
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
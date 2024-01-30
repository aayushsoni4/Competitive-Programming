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
int MOD = 1e9 + 7;

int func(int prev, int prev2, int i, int n, string& s, vector<vector<vector<int>>> &dp){
    if(i>=n){
        return 1;
    }
    if(dp[i][prev][prev2]!=-1){
        return dp[i][prev][prev2];
    }
    int ans = 0;
    if(s[i]=='a'){
        if(prev==2 and prev2==1){
            ans+=func(0,0,i+1,n,s,dp);
        }
        else{
            ans+=func(1,prev,i+1,n,s,dp);
        }
    }
    else if(s[i]=='b'){
        if(prev==1){
            ans+=func(0,0,i+1,n,s,dp);
        }
        else{
            ans+=func(1,prev,i+1,n,s,dp);
        }
    }
}

void solve(){
    int m, p=0, q;
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3,vector<int>(3,-1)));
    cout << func(0,0,0,n,s,dp) << endl;

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
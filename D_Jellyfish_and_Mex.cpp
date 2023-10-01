#include <bits/stdc++.h>
#define int               long long
#define f(i,a,b)          for(int i=a;i<b;i++)
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

int mex(unordered_map<int,int>mp){
    int ans = 0;
    while(mp.find(ans)!=mp.end()){
        ans++;
    }
    return ans;
}

void bruteforce(vector<int>a, unordered_map<int,int>&mp, int n){
    vector<int>per(n);
    iota(all(per),0);

    vector<int>ans;
    int res = INT_MAX;
    do{
        unordered_map<int,int>mpp = mp;
        int cnt = 0;

        f(i,0,n){
            mpp[a[per[i]]]--;
            if(mpp[a[per[i]]]==0)
                mpp.erase(a[per[i]]);
            int temp = mex(mpp);
            cnt+=temp;
        }
        if(cnt<res){
            res = cnt;
            ans=per;
        }
    }while(next_permutation(all(per)));
    
    cout << res << endl;

    y// cout << "Element removing index ";
    // printarray(per,n);
    // cout << "Element removed ";
    // f(i,0,n){
    //     cout << a[per[i]] << " ";
    // }
    // cout << endl;
 
    return;
}
 
int solvedp(int i, int MEX, vector<int>&v, vector<vector<int>>&dp, unordered_map<int,int>&mp){
    if(i==0){
        return MEX*(mp[0]-1);
    }
 
    if(dp[i][MEX]!=-1){
        return dp[i][MEX];
    }
 
    int a = INT_MAX, b = INT_MAX;
 
    a = (mp[v[i]]-1)*MEX + min(v[i],MEX) + solvedp(i-1,min(MEX,v[i]),v,dp,mp);
    b = solvedp(i-1,MEX,v,dp,mp);
 
    return dp[i][MEX] = min(a,b);
}
 
void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    inputarray(a,n);
    sort(all(a));
    unordered_map<int,int>mp;
    f(i,0,n){
        mp[a[i]]++;
    }
    int ans = 0;
    set<int>st(all(a));

    vector<int>v;
    for(auto i:st){
        v.pb(i);
    }
    n = v.size();
    int m = mex(mp);
    reverse(all(v));
    vector<vector<int>>dp(n+100,vector<int>(n+10,-1));

    cout << solvedp(n-1,m,v,dp,mp) << endl;
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
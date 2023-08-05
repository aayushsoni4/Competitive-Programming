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
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout<<endl;
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
bool check(vector<pair<int,int>>&seg, int& mid,vector<int>&q, int n,int m){
    int a[m+1]={0};
    f(i,0,mid+1){
        a[q[i]]=1;
    }
    f(i,1,m+1){
        a[i]+=a[i-1];
    }
    for(auto i: seg){
        int l=i.first,r=i.second;
        int one = (i.second-i.first+3)/2;
        if(one<=a[r]-a[l-1]){
            return true;
        }
    }
    return false;
}

void solve(){
    int n, m, p=0;
    cin >> n >> m;
    vector<pair<int,int>>seg;
    f(i,0,m){
        int l,r;
        cin >> l >> r;
        seg.pb({l,r});
    }    
    int que;
    cin >> que;
    vector<int>q(que);
    f(i,0,que){
        cin >> q[i];
    }
    int l=0,r=que-1;
    int ans=-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(seg,mid,q,que,n)){
            ans=mid+1;
            r=mid-1;
        }
        else{
            l=mid+1;
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
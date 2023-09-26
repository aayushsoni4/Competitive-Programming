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
    cin >> m >> n;
    string s;
    cin >> s;
    int l[n], r[n];
    inputarray(l,n);
    inputarray(r,n);
    cin >> q;
    int que[q];
    inputarray(que,q);
    vector<int>v(m+1,0);
    f(i,0,m){
        int idx = 0;
         int t1 = 0;
        int t2 = n-1;
        while(t1<=t2){
            int mid = (t1+t2)/2;
            if(r[mid]-1<i){
                t1 = mid+1;
            }
            else if(l[mid]-1>i){
                t2 = mid-1;
            }
            else{
                idx=mid;
                break;
            }
        }
        // cout<<idx<<endl;
        int a = l[idx]-1;
        int b = r[idx]-1;
        v[i]=b+(a-i);
    }
    // printarray(v,m);
    vector<int>cnt(m+1,0);
    f(i,0,q){
        int idx = 0;
        int t1 = 0;
        int t2 = n-1;
        while(t1<=t2){
            int mid = (t1+t2)/2;
            if(r[mid]-1<que[i]-1){
                t1 = mid+1;
            }
            else if(l[mid]-1>que[i]-1){
                t2 = mid-1;
            }
            else{
                idx=mid;
                break;
            }
        }
        // cout << idx << endl;

        int a = l[idx]-1;
        int b = r[idx]-1;

        // // cout << a <<  " " << b << endl;
        
        int st = min(que[i]-1,a+b-que[i]+1);
        int en = max(que[i]-1,a+b-que[i]+1);

        // // cout << st << " " << en << endl;

        cnt[st]++;
        cnt[en+1]--;    
    }
    f(i,1,m){
        cnt[i]+=cnt[i-1];
    }
    
    for(int i=0;i<m;i++){
        cnt[i]%=2;
    }
    f(i,0,m){
        if(cnt[i]==1){
            swap(s[v[i]],s[i]);
            cnt[v[i]]=0;
        }
    }
    cout << s << endl;

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
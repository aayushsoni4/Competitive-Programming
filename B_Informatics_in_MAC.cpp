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

int mex(int a[], int n){
    sort(a,a+n);
    int m = 0;
    f(i,0,n){
        if(a[i]==m){
            m++;
        }
    }
    return m;
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    int a[n],c[n];
inputarray(a,n);
    f(i,0,n){
        c[i] = a[i];
        if(a[i]==0){
            p++;
        }
    }
    if(p==0){
        cout << n << endl;
        f(i,0,n){
            cout << i+1 << " " << i+1 << endl;
        }
        return;
    }
    if(p==1){
        cout << -1 << endl;
        return;
    }
    int mx = mex(c,n);
    vector<vector<int>>ans;
    int temp1 = 1,temp2=-1;
    int cnt = mx;
    int ct[mx]={0};
    f(i,0,n){
        if(a[i]<mx){
            if(ct[a[i]]==0){
                ct[a[i]]++;
                cnt--;
                if(cnt==0){
                    temp2 = i+1;
                    p=i+1;
                    break;
                }
            }
        }
    }
    if(temp2==-1){
        cout << -1 << endl;
        return;
    }
    ans.pb({temp1,temp2});

    vector<int>v;
    f(i,p,n){
        v.pb(a[i]);
    }
    int b[v.size()];
    f(i,0,v.size()){
        b[i] = v[i];
    }
    int mx1 = mex(b,v.size());
    if(mx1!=mx){
        cout << -1 << endl;
        return;
    }
    cout << 2 << endl;
    cout << temp1 << " " << temp2 << endl;
    cout << temp2+1 << " " << n << endl;
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
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

void solve(){
    int n, m, p=0, q;
    cin >> n;
    int a[n];
    inputarray(a,n);
    vector<pair<int,int>>vp;
    f(i,0,n){
        vp.pb({a[i],i});
    }
    sort(all(vp));
    int i=0,j=n-1;
    
    if(n==1){
        cout << "NO" << endl;
        return;
    }
    while(i<j){
        if(vp[j].first==1){
            p=j;
            break;
        }
        vp[i].first++;
        vp[j].first--;
        i++;
        j--;
    }
    int k = j+1;
    // cout << i << " " << j << endl;
    if(i==j){
        if(vp[i].first>1){
            vp[i].first--;
            vp[0].first++;
        }
        else if(vp[n-1].first>1){
            vp[i].first++;
            vp[n-1].first--;
        }
    }
    else{
        while(i<=j){
            while(k<n and vp[k].first==1){
                k++;
            }
            if(k>=n){
                break;
            }
            vp[i].first++;
            i++;
            vp[k].first--;
        }
    }

    
    int ans[n];
    f(i,0,n){
        ans[vp[i].second]=vp[i].first;
    }
    // printarray(ans,n);
    f(i,0,n){
        if(ans[i]==a[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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
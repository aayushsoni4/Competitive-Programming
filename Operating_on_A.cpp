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
    int arr[n];
    int brr[n];
    inputarray(arr,n);
    inputarray(brr,n);
    vector<int>pref1(n,arr[0]);
    vector<int>pref2(n,brr[0]);
    f(i,1,n){
        pref1[i]=pref1[i-1]+arr[i];
        pref2[i]=pref2[i-1]+brr[i];
    }
    vector<int>odd1,odd2,even1,even2;
    f(i,0,n){
        if(i%2==0){
            even1.pb(pref1[i]);
            even2.pb(pref2[i]);
        }
        else{
            odd1.pb(pref1[i]);
            odd2.pb(pref2[i]);
        }
    }
    sort(all(odd1));
    sort(all(odd2));
    sort(all(even1));
    sort(all(even2));  
    if(odd1==odd2 && even1==even2 && pref1[n-1]==pref2[n-1]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
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
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
    int a[n];
    inputarray(a,n);
    vector<int>pref(n,0);
    pref[0]=a[0];
    f(i,1,n){
        pref[i]=pref[i-1]+a[i];
    }
    cin >> q;
    // printarray(pref,n);
    while(q--){
        int l, u;
        cin >> l >> u;
        l--;
        int ans = l;
        int r=n-1;
        int sections = a[l];
        int performance = u*sections - ((sections-1)*sections)/2;
        int x = l;
        // cout << performance << endl;
        while(l<=r){
            int mid = (l+r)/2;
            sections = pref[mid]-((x>0)?pref[x-1]:0);
            int newperformance = u*sections - ((sections-1)*sections)/2;
            // cout << l << " " << r << " " << mid << " - > " << performance << " " << newperformance << " " << sections << endl;
            if(newperformance>performance){
                ans=mid;
                performance=newperformance;
                if(sections-1>=u){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(newperformance==performance){
                    ans=min(ans,mid);
                }
                if(sections-1>=u){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        cout << ans+1 << " ";
        // cout << "\n\n";
    }
    cout << endl;



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
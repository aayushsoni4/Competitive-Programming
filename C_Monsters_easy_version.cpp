#include <bits/stdc++.h>
#define int               long long
#define f(i,a,b)          for(int i=a;i<b;i++)
#define mp                make_pair
#define pb                push_back
#define all(a)            a.begin(),a.end()
#define arraysort(a)      sort(a,a+n)
#define endl              "\n"    
#define inputarray(a, n)  f(i, 0, n) { cin >> a[i]; }
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout<<endl;
using namespace std;

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while (t--){
        int n, m, p=0, q;
        cin >> n;
        int a[n];
        inputarray(a,n);
        arraysort(a);
        f(i,0,n){
            if(a[i]==1){
                continue;
            }
            else{
                p=i;
                break;
            }
        }
        int ans = 0;
        if(p==0){
            ans+=a[0]-1;
            a[0]=1;
            p++;
        }
        f(i,p,n){
            if(abs(a[i]-a[i-1])<=1){
                continue;
            }
            else{
                ans+=a[i]-a[i-1]-1;
                a[i]=a[i-1]+1;
            }
        }
        cout << ans << endl;

    }
}
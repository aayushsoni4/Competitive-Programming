#include <bits/stdc++.h>
// #define int               long long
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
        int n, m, p=-1, q;
        cin >> n;
        int a[n];
        inputarray(a,n);
        f(i,0,n){
            int l=0,r=i;
            int mid;
            int ans;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid]>=i-mid+1){
                    ans=i-mid+1;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}
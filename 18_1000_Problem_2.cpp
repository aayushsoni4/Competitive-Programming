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
        cin >> n >> m;
        int a[n][m];
        int mn=1e9;
        f(i,0,n){
            f(j,0,m){
                cin >> a[i][j];
                mn=min(abs(a[i][j]),mn);
                if(a[i][j]<0){
                    p++;
                }
                a[i][j]=abs(a[i][j]);
            }
        }
        int sum=0;
        if(p%2==1){
            sum+=mn;
            sum*=-2;
        }       
        f(i,0,n){
            f(j,0,m){
                sum+=a[i][j];
            }
        }
        cout << sum << endl;

    }
}
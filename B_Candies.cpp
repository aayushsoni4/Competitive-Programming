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
    int testcases=1;
    cin >> testcases;
    while (testcases--){
        int n, m, p=0, q;
        cin >> n;
        if(n%2==0){
            cout << -1 << endl;
            continue;
        }        
        vector<int>ans;
        while(n!=1){
            if(((n+1)/2)%2!=0){
                ans.pb(1);
                n=(n+1)/2;
            }
            else{
                ans.pb(2);
                n=(n-1)/2;
            }
        }
        cout << ans.size() << endl;
        reverse(all(ans));
        printarray(ans,ans.size());
    }
}
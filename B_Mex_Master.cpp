// MAI CHUTIYA HU

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
        int n, p=1, q;
        cin >> n;
        int a[n];
        inputarray(a,n);
        set<int>s;
        arraysort(a);
        map<int,int>m;
        f(i,0,n){
            m[a[i]]++;
            s.insert(a[i]);
        }
        if(a[0]!=0){
            cout << 0 << endl;
            continue;
        }
        if(n%2==1){
            if(m[0]<=(n+1)/2){
                cout << 0 << endl;
                continue;
            }
        }
        if(n%2==0){
            if(m[0]<=(n)/2){
                cout << 0 << endl;
                continue;
            }
        }
        if(a[n-1]==1){
            cout << 2 << endl;
        }
        else{
            cout << 1 << endl;
        }
        // printarray(ans,n);
    }
}
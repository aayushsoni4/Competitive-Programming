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
#define cyes              cout << "YES" << endl;
#define cno               cout << "NO" << endl;
#define ch(p)             if(p==1)


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
        if(a[0]!=1){
            cout << "NO" << endl;
            continue;
        }
        p=1;
        q=0;
        f(i,1,n){
            if(p<a[i]){
                q=1;
                break;
            }
            p+=a[i];
        }
        if(q)
            cno
        else
            cyes
    }
}
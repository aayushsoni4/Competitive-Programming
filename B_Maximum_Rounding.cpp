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
    int n, m, p=-1, q;
    string s;
    cin >> s;
    n = s.length();
    int c = 0;
    s = '0'+s;

    for(int i=n;i>0;i--){
        if(s[i]>='5'){
            if(s[i-1]<'9')
                s[i-1]++;
            s[i]='0';
        }
        else{
            p=i;
            break;   
        }
    }
    
    string w= "";
    int i =0;
    if(s[0]=='0'){
        i++;
    }
    while(i<s.length()){
        w+=s[i];
        i++;
    }
    s=w;
    
    p=-1;
    f(i,0,s.length()){
        if(s[i]>='5'){
            p=i;
            s[i]='0';
            break;   
        }
    }
    if(p==-1){
        cout << s << endl;
        return;
    }
    if(p==0){
        cout << "1";
        while(p<s.length()){
            s[p] = '0';
            p++;
        }
        cout << s << endl;
    }
    else{
        s[p-1]++;
        while(p<s.length()){
            s[p]='0';
            p++;
        }
        if(s[0]>='5'){
            s[0]='0';
            cout << "1";
        }
        cout << s << endl;
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

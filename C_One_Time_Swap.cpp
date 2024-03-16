#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    long long freq[26] = {0}, f = 0;
    
    for (char c : s) {
        freq[c - 'a']++;
        if(freq[c - 'a'] > 1)
            f = 1;
    }

    long long total = s.size() * (s.size() - 1) / 2;
    for (int i = 0; i < 26; i++) {
        total -= freq[i] * (freq[i] - 1) / 2; 
    }

    cout << total+f << "\n"; 

    return 0;
}

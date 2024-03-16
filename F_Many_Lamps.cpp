#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (K > N || K % 2 != N % 2) {
        cout << "No\n";
        return 0;
    }

    vector<int> degree(N+1, 0);
    for (auto edge : edges) {
        degree[edge.first]++;
        degree[edge.second]++;
    }

    int odd_degree_count = 0;
    for (int d : degree) {
        if (d % 2 == 1) {
            odd_degree_count++;
        }
    }

    if (odd_degree_count > K) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    for (int i = 1; i <= M; ++i) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

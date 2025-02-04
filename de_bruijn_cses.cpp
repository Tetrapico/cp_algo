#include <bits/stdc++.h>
using namespace std;

string de_bruijn(int n) {
    int total = 1 << n;  // 2^n different substrings
    unordered_set<int> visited;
    string result;

    function<void(int)> dfs = [&](int node) {
        for (int bit = 0; bit < 2; bit++) {
            int next = ((node << 1) & (total - 1)) | bit;  // Append bit to last (n-1) bits
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                dfs(next);
                result += ('0' + bit);  // Append bit to result
            }
        }
    };

    dfs(0);  // Start DFS from node 0 (all 0s)
    result += string(n - 1, '0');  // Append (n-1) leading zeros to make it cyclic
    reverse(result.begin(), result.end());  // Reverse to get correct order

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << de_bruijn(n) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
// Z-algorithm function
void ZAlgorithm(const string &s) {
    int n = s.length();
    vector<int> z(n, 0); // Z-array to store Z-values
    
    // Initialize the left and right pointers of the window
    int left = 0, right = 0;
    vector<int>fuck;
    for (int i = 1; i < n; i++) {
        // Case 1: i is outside the current window
        if (i > right) {
            left = right = i;
            while (right < n && s[right] == s[right - left]) {
                right++;
            }
            z[i] = right - left;
            right--;
        } else {
            // Case 2: i is inside the current window
            int k = i - left;
            if (z[k] < right - i + 1) {
                z[i] = z[k];
            } else {
                left = i;
                while (right < n && s[right] == s[right - left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
        }
        if(i+z[i]==n)cout<<i<<" ";
    }
    cout<<n;
    // Print the Z-array
   
    cout << endl;
}
 
int main() {
    // Input string
    string s;
    cin >> s;
    
    // Call the Z-algorithm function
    ZAlgorithm(s);
 
    return 0;
}

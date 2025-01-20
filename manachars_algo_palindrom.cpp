#include <iostream>
#include <vector>
#include <string>

using namespace std;

string manacher(const string& s) {
    // Transform the string by inserting '#' between characters and at the ends
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int n = t.size();
    vector<int> p(n, 0);  // Array to store the radius of palindromes
    int center = 0, right = 0;  // center and rightmost boundary of the current palindrome
    int maxLength = 0, maxCenter = 0;  // To store the maximum length and center of the palindrome

    // Iterate through the transformed string
    for (int i = 0; i < n; i++) {
        // Mirror of the current position i around the center
        int mirror = 2 * center - i;

        if (i < right) {
            p[i] = min(right - i, p[mirror]);  // Use previously computed palindrome information
        }

        // Try to expand the palindrome centered at i
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }

        // If the palindrome expanded past the right boundary, update the center and right
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        // Update the max palindrome length and its center
        if (p[i] > maxLength) {
            maxLength = p[i];
            maxCenter = i;
        }
    }

    // The longest palindromic substring will be from maxCenter - maxLength to maxCenter + maxLength
    string result = s.substr((maxCenter - maxLength) / 2, maxLength);
    return result;
}

int main() {
    string s;
    cin >> s;
    string result = manacher(s);
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}

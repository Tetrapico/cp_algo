#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute m^exp % MOD using binary exponentiation
long long mod_exp(long long m, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * m) % MOD;
        }
        m = (m * m) % MOD;
        exp /= 2;
    }
    return result;
}

// Function to calculate the number of distinct necklaces
long long count_distinct_necklaces(int n, int m) {
    long long sum = 0;
    
    // Loop through all possible rotations and sum up the number of valid colorings
    for (int k = 0; k < n; k++) {
        int g = gcd(n, k);
        sum = (sum + mod_exp(m, g)) % MOD;
    }
    
    // Divide by n (modular inverse of n)
    long long result = (sum * mod_exp(n, MOD - 2)) % MOD;  // Fermat's little theorem for modular inverse
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << count_distinct_necklaces(n, m) << endl;
    return 0;
}

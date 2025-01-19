#include <iostream>
#include <vector>
using namespace std;
 
const int MOD = 1e9 + 7;
 
// Function to compute (base^exp) % mod using modular exponentiation
long long modular_exponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
 
// Function to calculate the number of valid bracket sequences
long long compute_catalan(int n) {
    if (n % 2 != 0) {
        return 0; // n must be even for valid bracket sequences
    }
    n /= 2; // Catalan number is defined for n/2 pairs of brackets
 
    // Precompute factorials and modular inverses
    int max_factorial = 2 * n;
    vector<long long> fact(max_factorial + 1, 1);
    for (int i = 2; i <= max_factorial; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
 
    // Compute modular inverses using Fermat's Little Theorem
    vector<long long> inv_fact(max_factorial + 1, 1);
    inv_fact[max_factorial] = modular_exponentiation(fact[max_factorial], MOD - 2, MOD);
    for (int i = max_factorial - 1; i >= 1; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
 
    // Calculate Catalan number
    long long numerator = fact[2 * n];
    long long denominator = (fact[n] * fact[n + 1]) % MOD;
    long long catalan_number = (numerator * inv_fact[n] % MOD * inv_fact[n + 1]) % MOD;
 
    return catalan_number;
}
 
int main() {
    int n;
    cin >> n;
    cout << compute_catalan(n) << endl;
    return 0;
}

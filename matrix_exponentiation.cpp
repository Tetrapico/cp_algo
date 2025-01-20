#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to multiply two 2x2 matrices modulo MOD
void matrix_multiply(long long A[2][2], long long B[2][2]) {
    long long res[2][2];
    res[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    res[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    res[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    res[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

    // Copy the result back to A
    A[0][0] = res[0][0];
    A[0][1] = res[0][1];
    A[1][0] = res[1][0];
    A[1][1] = res[1][1];
}

// Function to perform matrix exponentiation
void matrix_exponentiation(long long M[2][2], long long n) {
    long long result[2][2] = {{1, 0}, {0, 1}}; // Identity matrix

    while (n > 0) {
        if (n % 2 == 1) {
            matrix_multiply(result, M); // Multiply result by M
        }
        matrix_multiply(M, M); // Square the matrix
        n /= 2;
    }

    // Copy the result back to M
    M[0][0] = result[0][0];
    M[0][1] = result[0][1];
    M[1][0] = result[1][0];
    M[1][1] = result[1][1];
}

// Function to compute F_n modulo MOD
long long fibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long M[2][2] = {{1, 1}, {1, 0}};
    matrix_exponentiation(M, n - 1);

    return M[0][0]; // Top-left element gives F_n
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}

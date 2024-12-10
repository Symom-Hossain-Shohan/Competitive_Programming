#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

// Function to perform modular exponentiation
// It returns (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
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

// Function to find modular inverse using Fermat's Little Theorem
// It returns (a^(mod-2)) % mod
long long modInverse(long long a, long long mod) {
    return modExp(a, mod - 2, mod);
}

int main() {
    int N;
    cin >> N;

    vector<long long> redWeights(N), greenWeights(N);
    for (int i = 0; i < N; ++i) {
        cin >> redWeights[i] >> greenWeights[i];
    }

    // Calculate sum of average weights for each box
    long long totalAverageWeight = 0;
    for (int i = 0; i < N; ++i) {
        long long averageWeight = (redWeights[i] + greenWeights[i]) / 2;
        totalAverageWeight = (totalAverageWeight + averageWeight) % MOD;
    }

    // Loop over each K from 1 to N
    for (int K = 1; K <= N; ++K) {
        long long P = (K * totalAverageWeight) % MOD;
        long long Q = N;

        // Compute (P * Q^-1) % MOD
        long long Q_inv = modInverse(Q, MOD);
        long long result = (P * Q_inv) % MOD;

        // Output result for this K
        cout << result << endl;
    }

    return 0;
}

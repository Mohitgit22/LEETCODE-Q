class Solution {
public:

    int countPrimes(int n) {
if (n <= 2) return 0;  // No primes less than 2

        vector<int> prime(n, 1);  // Initialize a boolean array of size n with all entries as 1 (true)
        prime[0] = prime[1] = 0;  // 0 and 1 are not prime

        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;  // Mark multiples of i as non-prime
                }
            }
        }
       
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i] == 1) {
                count++;
            }
        }

        return count;
    }
};
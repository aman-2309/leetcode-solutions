class Solution {
public:
    const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;
        while (b) {
            if (b & 1)
                ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        long long num = 1, den = 1;

        for (int i = 1; i <= r; i++) {
            num = (num * (n - i + 1)) % MOD;
            den = (den * i) % MOD;
        }

        return (num * power(den, MOD - 2) % MOD);
    }
    int countValidSequences(int n, int k) {
        long long total = nCr(n - 1, k - 1);
        long long odd = 0;

        if ((n - k) % 2 == 0) {
            int S = (n - k) / 2;
            odd = nCr(S + k - 1, k - 1);
        }

        return (total - odd + MOD) % MOD;
    }
};
class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
        return fib(n+1);
    }

    int fib(int n) {
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }

        int result;
        if (n == 0 || n == 1) {
            result = n;
        } else {
            result = fib(n - 2) + fib(n - 1);
        }

        cache[n] = result;
        return result;
    }
};

// O(2^n) -> O(n)

// fib(0) = 0
// fib(1) = 1

// fib(2)
// return fib(1) + fib(0) = 1 + 0 = 1

// fib(3)
// return fib(2) + fib(1) = 1 + 1 = 2

// fib(4)
// return fib(3) + fib(2) = (fib(2) = (fib(1) + fib(0)) + fib(1)) + (fib(1) + fib(0)) = 3
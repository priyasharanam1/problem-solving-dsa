class Solution {
public:
    bool isPrime(int num) {
        if(num < 2) return false;
        for(int j = 2; j * j <= num; j++) {
            if(num % j == 0) return false;
        }
        return true;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        vector<int> ans(2, -1); // Initialize with -1

        int minDiff = INT_MAX;

        for(int i = left; i <= right; i++) {
            if(isPrime(i)) {
                if(!primes.empty()) {
                    int diff = i - primes.back();
                    if(diff < minDiff) {
                        minDiff = diff;
                        ans[0] = primes.back();
                        ans[1] = i;
                    }
                }
                primes.push_back(i);
            }
        }
        return ans;
    }
};

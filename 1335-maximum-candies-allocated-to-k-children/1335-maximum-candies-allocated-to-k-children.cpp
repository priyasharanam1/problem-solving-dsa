class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        if (accumulate(candies.begin(), candies.end(), 0LL) < k) 
            return 0;  // If total candies are less than k, return 0

        int left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long count = 0;

            // Count how many children can get 'mid' candies
            for (int c : candies) {
                count += c / mid;
            }

            if (count >= k) { // If we can distribute to at least k children
                result = mid;  // Store the possible answer
                left = mid + 1; // Try for more candies per child
            } else {
                right = mid - 1; // Reduce candies per child
            }
        }
        return result;
    }
};
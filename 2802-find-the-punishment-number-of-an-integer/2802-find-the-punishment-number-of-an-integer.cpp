class Solution {
public:
    bool canPartition(int num, int target) {
        if (num < target || target < 0) 
            return false;
        if (num == target) 
            return true;

        // Try different ways to split the number
        return (canPartition(num / 10, target - (num % 10)) ||   // Last 1 digit
                canPartition(num / 100, target - (num % 100)) || // Last 2 digits
                canPartition(num / 1000, target - (num % 1000))); // Last 3 digits
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers 1 to n
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(square, i)) { // Check if square can be split into parts summing to i
                punishmentNum += square;
            }
        }

        return punishmentNum;
    }
};

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int white = 0;

        // Count white blocks in the first window
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W') white++;
        }

        int minWhite = white;

        // Sliding window to find the minimum white blocks in any window of size k
        for(int i = k; i < n; i++) {
            if(blocks[i] == 'W') white++; // Add the new block to the window
            if(blocks[i - k] == 'W') white--; // Remove the leftmost block from the window
            minWhite = min(minWhite, white);
        }

        return minWhite;
    }
};

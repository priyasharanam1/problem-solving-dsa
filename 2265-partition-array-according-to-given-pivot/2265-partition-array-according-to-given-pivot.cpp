class Solution {
public:
    void partition(vector<int>& nums, int pivot, vector<int>& left, vector<int>& equal, vector<int>& right) {
        for (int num : nums) {
            if (num < pivot) left.push_back(num);
            else if (num == pivot) equal.push_back(num);
            else right.push_back(num);
        }
    }

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, equal, right;
        partition(nums, pivot, left, equal, right);

        // Concatenating the results
        vector<int> result;
        result.reserve(nums.size()); // Preallocate memory for efficiency
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), right.begin(), right.end());

        return result;
    }
};

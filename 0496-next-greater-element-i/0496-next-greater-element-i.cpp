class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // nums2 ke sabhi elements ke liye
        // respective nge hum ek map mein store karenge
        // aur end mein nums1 ke liye bhi wahi se nge mil jaenge
        unordered_map<int, int> m;
        int n = nums2.size();

        // nums2 ke last element ke liye koi nge nhi hai so = -1
        m[nums2[n - 1]] = -1;
        stack<int> st;
        // right mein jakar nge dekhna hai, isliye right se hi traverse karenge
        // nums2 ke last element ko sabse pehle stack mein daal dein
        st.push(nums2[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            // jab tak top < curEl, keep popping the stack
            while (st.size() && st.top() < nums2[i])
                st.pop();
            // agar stack empty ho gya to = -1
            if (st.empty())
                m[nums2[i]] = -1;
            // nahin to top > curEl, therefore map[curEl] = nge[curEl] = top
            else
                m[nums2[i]] = st.top();
            // push each curEl in stack
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};
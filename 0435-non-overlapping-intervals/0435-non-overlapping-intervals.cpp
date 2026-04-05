class Solution {
public:
    static const bool comp(vector<int>a, vector<int>b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1, lastEnding = intervals[0][1];
        for(int i=0;i<n;i++){
            if(intervals[i][0] >= lastEnding){
                cnt++;
                lastEnding = intervals[i][1];
            }
        }
        return n-cnt;
    }
};
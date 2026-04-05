class Solution {
public:
    static const bool comp(vector<int>a, vector<int>b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //sort based on finish time of each interval
        sort(intervals.begin(), intervals.end(), comp);
        //first interval is already non-overlapping
        int last=0, cnt=1;
        for(int cur=1; cur<n; cur++){
            if(intervals[cur][0]-intervals[last][1] >= 0){
                cnt++;
                last=cur;
            }
        }
        return n-cnt;
    }
};
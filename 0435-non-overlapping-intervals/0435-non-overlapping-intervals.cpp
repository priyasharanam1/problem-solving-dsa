class Solution {
public:
    static const bool comp(vector<int>a, vector<int>b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        int cnt=0;
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]-end<0){
                cnt++;
            }
            else{
                end=intervals[i][1];
            }
        }
        return cnt;
    }
};
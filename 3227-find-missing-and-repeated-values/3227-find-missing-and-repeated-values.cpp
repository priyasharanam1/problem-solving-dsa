#define ll long long
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m*m;

        ll s=0, s2=0;
        ll sn = ((ll)n*(n+1))/2;
        ll s2n = ((ll)n*(n+1)*(2*n+1))/6;

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                s += (ll)grid[i][j];
                s2 += ((ll)grid[i][j]*grid[i][j]);
            }
        }
        
        //x-y
        int val1 = (int)(sn - s);

        //x2-y2
        int val2 = (int)(s2n - s2);
        val2 = val2/val1;

        int x = (val1 + val2)/2;
        int y = x-val1;

        return {y,x};

    }
};
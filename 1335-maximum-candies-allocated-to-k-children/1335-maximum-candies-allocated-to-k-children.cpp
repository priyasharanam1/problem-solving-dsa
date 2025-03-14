class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        bool sumLessThanK = true;
        //if sum of all elements is less than k
        //it means we can't allocate equal number of candies among all
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += candies[i];
            if(sum>=k) sumLessThanK=false; 
        }
        if(sumLessThanK) return 0;

        //find the maximum element
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,candies[i]);
        }

        //apply binary search on answers from 1 to maxi
        int left=1;
        int right=maxi;
        int result=0;
        while(left<=right){
            int mid = left+(right-left)/2;
            long long count=0;
            for(int i=0;i<n;i++){
            count += candies[i]/mid;
            }
            //an answer has been found
            //check for greater possibilities on right
            if(count>=k){
                result=mid;
                left=mid+1;
            }
            //else check for lesser possibility on left 
            else{
                right=mid-1;
            }
        }
        return result;
    }
};
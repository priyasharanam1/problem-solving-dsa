class Solution {
    int findDigitSum(int n){
        int sum=0;
        while(n>0){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        //map to store frequency for each digit sum
        unordered_map<int,int>digitSumFreq;
        int maxCnt=0, maxCntGroups=0;

        for(int i=1;i<=n;i++){
            int digSum = findDigitSum(i);
            digitSumFreq[digSum]++;
            maxCnt = max(maxCnt,digitSumFreq[digSum]);
        }

        for(auto sum : digitSumFreq){
            if(sum.second == maxCnt) maxCntGroups++;
        }

        return maxCntGroups;
    }
};
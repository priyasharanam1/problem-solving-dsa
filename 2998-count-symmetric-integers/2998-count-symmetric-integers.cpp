class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            int digits = (log10(i)+1);
            if(digits&1) continue;
            else{
                 string num = to_string(i);
                 int l=0, r=num.length()-1;
                 int sum1=0,sum2=0;
                 while(l<=r){
                     sum1+=num[l];
                     sum2+=num[r];
                     l++;
                     r--;
                 }
                 if(sum1==sum2) cnt++;
            }
        }
        return cnt;
    }
};
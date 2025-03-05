class Solution {
public:
    long long coloredCells(int n) {
        //logic:
        //number of new cells coloured every new minute(n) = 4*(n-1)
        //1 min : 1+(4*0)
        //2 min : 1+(4*(0+1))
        //3 min : 1+(4*(0+1+2))
        //n min : 1+(4*(0+1+2+...+(n-1)))
        //sum of first n-1 natural numbers : (n-1)*n/2
        return 1 + 4LL * n * (n-1) / 2;
    }
};
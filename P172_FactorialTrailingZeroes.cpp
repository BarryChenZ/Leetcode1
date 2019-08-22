class Solution {
public:
    int trailingZeroes(int n) {
        //看有幾個5
        int res = 0;
        double divisor = 1;
        while(true){
            divisor *= 5;
            if(divisor > n) break;
            res += n / divisor;
        }
        return res;
    }
};

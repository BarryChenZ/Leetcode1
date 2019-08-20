class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long aNum = numerator;
        long long bNum = denominator;
        bool negative = (numerator < 0) != (denominator < 0);
        aNum = abs(aNum);
        bNum = abs(bNum);
        long long aDigit = aNum / bNum;
        string result = to_string(aDigit);
        
        long long aRemainder = (aNum % bNum)*10;
        
        if(negative && (aDigit != 0 || aRemainder != 0)){
            result = string("-") + result;
        }
        //判斷是否有迴圈
        if(aRemainder != 0){
            result.append(".");
            unordered_map<int, int> aRepeatMap(64);
            
            while(aRemainder != 0){
                if(aRepeatMap[aRemainder] != 0){
                    result.insert(aRepeatMap[aRemainder], "(");
                    result.append(")");
                    break;
                }
                else{
                    aRepeatMap[aRemainder] = result.size();
                    result.append(to_string(aRemainder/bNum));
                    aRemainder = (aRemainder%bNum) * 10;
                }
            }
        }
        
        return result;
    }
};

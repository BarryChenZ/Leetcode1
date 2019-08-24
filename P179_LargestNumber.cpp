class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if( nums.size() == 0 ) return "";
        // sort the numbers accroding to compareInts fn
        sort( nums.begin(), nums.end(), compareInts );
        // if the heighest number is 0 then return 0
        if( nums[0]  == 0 ) return "0";
        
        string result = "";
        for( auto n : nums )
            result += to_string( n );
        
        return result;
    }
    static bool compareInts( int a, int b ) {
        string A = to_string( a );
        string B = to_string( b );
        long ab = stol( A + B );
        long ba = stol( B + A );
        return ab > ba;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1;
        int temp = 0;
        for(int i = 0; i < gas.size(); i++){
            if(gas[i] >= cost[i]) {
                temp = traval(gas, cost, i);
                if(temp >= 0) res = i;
            }
            
        }
        return res;
    }
    int traval(vector<int>& gas, vector<int>& cost, int idx){
        int temp = 0;
        for(int i = 0; i < gas.size(); i++){
            //順:
            temp += gas[idx] - cost[idx];
            if(temp < 0) return -1;
            idx++;
            if(idx >= gas.size()) idx = 0;
        }
        return temp;
        
    }
};

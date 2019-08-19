class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1, s2;
        s1.str(version1);
        s2.str(version2);
        while(true){
            string item1, item2;
            getline(s1, item1, '.');
            getline(s2, item2, '.');
            
            if (item1.empty() && item2.empty()) break;
            
            int val1 = !item1.empty() ? stoi(item1) : 0;
            int val2 = !item2.empty() ? stoi(item2) : 0;
            
            if (val1 > val2) return 1;
            else if (val1 < val2) return -1;
        }
        return 0;
    }
};

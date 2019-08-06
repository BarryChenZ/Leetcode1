class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()==0 || s.size()==1) return true;
        auto l = s.begin(), r = s.end()-1;
        while(l<=r){
            while(l<=r && !((*l>='a'&&*l<='z')||(*l>='A'&&*l<='Z')||(*l>='0'&&*l<='9')) ) l++;
            while(r>=l && !((*r>='a'&&*r<='z')||(*r>='A'&&*r<='Z')||(*r>='0'&&*r<='9')) ) r--;
            if (l>=r) return true;
            int num1 = (*l>='a'?*l-'a':*l-'A');
            int num2 = (*r>='a'?*r-'a':*r-'A');
            if (num1!=num2) return false;
            l++, r--;
        }
        return true;
    }
};

class Solution {
private:
    int find(int lvalue, int rvalue, int curr) {
        return max(0, min(lvalue, rvalue) - curr);
    }
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lvalue = height[l], rvalue = height[r];
        int ans = 0;
        int eval = 0;
        while(l < r) {
            //cout<<l<<"|"<<r<<endl; cout<<lvalue<<"|"<<rvalue<<endl;
            eval = lvalue <= rvalue ? ++l : --r;
            //cout<<eval<<", val: "<<find(lvalue, rvalue, height[eval])<<endl;
            ans += find(lvalue, rvalue, height[eval]);
            lvalue = max(lvalue, height[l]);
            rvalue = max(rvalue, height[r]);
        }
        return ans;
    }
};

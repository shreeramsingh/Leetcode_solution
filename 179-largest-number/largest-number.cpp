class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //here we are doing sorting but by comparing all type;
        auto myCompator = [](int &a,int &b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            if(s1+s2>s2+s1) return true;
            else return false;
        };
        sort(nums.begin(),nums.end(), myCompator);
        if(nums[0]==0){
            return "0";
        }
        string result="";
        for(int &num:nums){
            result+=to_string(num);
        }
        return result;
    }
};
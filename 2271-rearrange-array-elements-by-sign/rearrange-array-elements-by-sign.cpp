class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int a[n/2],b[n/2],i=0,j=0;
        for(int e : nums) 
        {
            if(e<0)
            {
                b[j] = e;
                j++;
            }
            else
            {
                a[i] = e;
                i++;
            }
        }
        for(int i = 0; i < n;i+=2)
        {
            nums[i]=a[i/2];
            nums[i+1] = b[i/2];
        }
        return nums;
    }
};
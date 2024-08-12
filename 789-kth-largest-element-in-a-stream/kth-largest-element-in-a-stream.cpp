class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>mini;
    int temp;
    KthLargest(int k, vector<int>& nums) {
        temp=k;
       for(int i=0;i<nums.size();i++)
       {
           mini.push(nums[i]);
           if(mini.size()>k)
           {
               mini.pop();
           }
       } 
    }
    
    int add(int val) {
        mini.push(val);
        if(mini.size()>temp){
            mini.pop();
        }
         return mini.top();
    }
   
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
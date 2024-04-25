class Solution {
    int sumdig(int n)
    {
        int sum=0;
        while(n>0)
        {
          int r=n%10; 
          sum+=r;
          n/=10;
        }
        return sum;   
    }
public:
    int addDigits(int num) {
        int ans;
        ans=sumdig(num);
        if(ans<10)
        {
            return ans;
        }
        return addDigits(ans);  
    }
};
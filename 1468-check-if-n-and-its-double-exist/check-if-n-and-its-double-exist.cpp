class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        //brute force solution
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i!=j && arr[i]*2==arr[j])
                    return true;
            }
        }
        return false;
        
        // map<double, int>m;
        // for(int i=0;i<arr.size();i++)
        // {
        //     if(m.count(arr[i]*2) || m.count( (double)arr[i]/2)){
        //         return true; 
        //     }
        //    m[arr[i]]++;
        // }
        // return false;
    }
};
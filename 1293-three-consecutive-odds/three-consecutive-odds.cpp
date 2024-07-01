class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int cont = 0; 

        for (int num : arr) { 
            if (num % 2 != 0) { 
                cont++; 
                if (cont == 3) { 
                    return true;
                }
            } else { 
                cont = 0;
            }
        }

        return false; 
    }
};
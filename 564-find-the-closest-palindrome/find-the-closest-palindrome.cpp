class Solution {
public:
    long func(long firstHalf, bool isEven){
        long resultNum = firstHalf;

        if(isEven == false){
            firstHalf /= 10;
        }

        while(firstHalf > 0){
            int digit = firstHalf % 10;
            resultNum = (resultNum * 10) + digit;

            firstHalf /=10;
        }
        return resultNum;
    }
    string nearestPalindromic(string n) {
        int l=n.size();

        int mid = l/2;

        int firstHalfLength = (l%2==0) ? mid :(mid+1);

        long firstHalf = stol(n.substr(0, firstHalfLength));

        vector<long> possibleResults;

        possibleResults.push_back(func(firstHalf, l%2 == 0));
        possibleResults.push_back(func(firstHalf+1, l%2 == 0));
        possibleResults.push_back(func(firstHalf-1, l%2 == 0));
        possibleResults.push_back((long)pow(10, l-1) - 1);
        possibleResults.push_back((long)pow(10, l) + 1);

        long diff = LONG_MAX;
        long result = INT_MAX;
        long OrignalNum = stol(n);

        for(long num : possibleResults){
            if(num == OrignalNum) continue;

            if(abs(num - OrignalNum) < diff){
                diff = abs(num - OrignalNum);
                result = num;
            } else if(abs(num - OrignalNum) == diff ){
                result = min(result, num);
            }
        }

        return to_string(result);
    }
};
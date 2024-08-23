class Solution {
public:
    string fractionAddition(string exp) {
        int nume = 0;
        int deno = 1;

        int i=0;
        int n= exp.size();
        while(i<n){
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (exp[i] == '-');

            if(exp[i] == '+' || exp[i] == '-'){
                i++;
            }

            //build the currNume
            while(i < n && isdigit(exp[i])){
                int val = exp[i]-'0';
                currNume = (currNume*10) + val;
                i++;
            }

            i++;//numerator / denominator //skipiing thr divisrio character '/

            if(isNeg == true){
                currNume *= -1;
            }

            //Build the currDeno
            while(i < n && isdigit(exp[i])){
                int val = exp[i] -'0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            int GCD = abs(__gcd(nume, deno));

            nume /= GCD;
            deno /= GCD;

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }
        int GCD = abs(__gcd(nume, deno));

        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};
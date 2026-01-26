class Solution {
public:

    bool isPrime(int x){
        if (x<2) return false;
        for(int i = 2;i*i <=x;i++) {
            if(x%i==0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string s =  to_string(num);

        int val = 0;
        for(char c : s) {
            val = val*10+(c-'0');
            if(!isPrime(val))
                return false;
        }

        val = 0;
        int place  = 1;
        for(int i = s.size()-1;i>=0;i--){
            val = place*(s[i]-'0') +val;
            place *= 10;
            if (!isPrime(val))
                return false;
        }
        return true;
        
    }
};
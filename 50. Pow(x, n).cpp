class Solution {
public:
    double myPow(double x, int n) {
         // Base case: agar n zero hai to x^0 = 1
        if (n == 0) return 1;

        // Agar n negative hai to x ko 1/x aur n ko -n karo
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double current_product = x;
        
        // Binary Exponentiation
        while (N > 0) {
            if (N % 2 == 1) {
                result *= current_product;  // Agar n odd hai, to ek extra multiply karo
            }
            current_product *= current_product;  // Power ko square karte raho
            N /= 2;  // n ko half karo
        }

        return result;
    }
};

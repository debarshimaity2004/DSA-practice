//166. Fraction to Recurring Decimal
//tc...O(n)
//sc...O(n)

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        res += to_string(n / d);
        n %= d;
        if (n == 0) return res;
        res += ".";
        unordered_map<long long, int> mp;
        while (n) {
            if (mp.find(n) != mp.end()) {
                res.insert(mp[n], "(");
                res += ")";
                break;
            }
            mp[n] = res.size();
            n *= 10;
            res += to_string(n / d);
            n %= d;
        }
        return res;
    }
};
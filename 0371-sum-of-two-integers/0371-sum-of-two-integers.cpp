class Solution {
public:
    int getSum(int a, int b) {
    while (b != 0) {
            int carry = (a & b) << 1; // Calculate carry
            a = a ^ b; // Sum without carry
            b = carry; // Update b with the carry
        }
        return a;
    }
};
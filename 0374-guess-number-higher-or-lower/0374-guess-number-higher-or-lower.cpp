/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
    int low = 1;
        int high = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            
            if (result == 0) {
                return mid;  // The guess is correct
            } else if (result == -1) {
                high = mid - 1;  // The picked number is lower, adjust the high boundary
            } else {
                low = mid + 1;  // The picked number is higher, adjust the low boundary
            }
        }
        
        return -1;  // This line is never reached if the guess API works correctly
    }
};
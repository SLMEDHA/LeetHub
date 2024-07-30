class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> stk;
        for (int asteroid : asteroids) {
            bool exploded = false;
            while (!stk.empty() && asteroid < 0 && stk.top() > 0) {
                if (stk.top() < -asteroid) {
                    stk.pop();  // Right-moving asteroid explodes
                } else if (stk.top() == -asteroid) {
                    stk.pop();  // Both asteroids explode
                    exploded = true;
                    break;
                } else {
                    exploded = true;  // Left-moving asteroid explodes
                    break;
                }
          }
            if (!exploded) {
                stk.push(asteroid);  // No collision or the left-moving asteroid didn't explode
            }
        }
        vector<int> result(stk.size());
        for (int i = stk.size() - 1; i >= 0; --i) {
            result[i] = stk.top();
            stk.pop();
        }
        return result;
    }
};
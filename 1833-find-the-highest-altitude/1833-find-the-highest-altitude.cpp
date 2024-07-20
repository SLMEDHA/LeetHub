class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_altitude = 0;
        int highest_altitude = 0;
        
        for (int net_gain : gain) {
            current_altitude += net_gain;
            highest_altitude =max(highest_altitude, current_altitude);
        }
        
        return highest_altitude;
    }
};
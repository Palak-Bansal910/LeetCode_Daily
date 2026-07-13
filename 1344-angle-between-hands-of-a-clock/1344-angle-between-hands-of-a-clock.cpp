class Solution {
public:
    double angleClock(int hour, int minute) {
        if(hour < 0 || hour > 12 || minute < 0 || minute > 60){
        cout << "Invalid input." << endl;
        return -1;
        }
        double minuteAngle = 6 * minute;
        double hourAngle = 30 * hour + (minute / (double)2);
        double angle = abs(hourAngle - minuteAngle);
        if(angle > 180){
            angle = 360 -angle;
        }
        return angle;
    }
};
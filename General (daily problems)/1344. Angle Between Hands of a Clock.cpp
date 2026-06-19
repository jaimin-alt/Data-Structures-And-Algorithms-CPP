#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double angleClock(int hour, int minutes) {
        // for 12 o clock we have to do hour = 0
        hour = hour %12;

        // hour kanta e total ketli minutes kaapi ? starting from 12 or 0
        double hourInMin= double(hour)*5;
        // jyare min kaanto 0 thi 60 vachhe game tya pahochyo hse tyare hour kaanto ketlo aagad gayo hse ? 

        // if min. 60 min nu chakra puru kare tyre hour kanto 5 min nu chakra puru kare

        // 60 min --> 5 min
        // currentmin --> (?)
        double FractionIncrease=(double(minutes)*5)/60;

        // we have to add this to the hour kanto to see where hour kaanto is currently in clock
        hourInMin+=FractionIncrease;
        
        // we have to find the angle between hour kanto and min kanto 
        // we have both hour kanto postiion and min kanto position in clock
        // get the difference of minutes between those two kaanta

        double startingMin = hourInMin;
        double endingMin = minutes;
        double diff = abs(startingMin-endingMin);

        // if 15 min diff --> 90 degree
        // given diff --> how much ? 

        double ans = (diff*90)/15;

        return min(ans,360-ans);
    }
};
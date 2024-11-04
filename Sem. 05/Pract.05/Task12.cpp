#include <iostream>
using namespace std;

unsigned int endOfPermormenceInMinutes(unsigned hours, unsigned minutes, unsigned duration) {
    unsigned int end = hours * 60 + minutes + duration;
    return end;
}

void makeEndFromMinutesToHoursAndMinutes(unsigned int minutes, unsigned int& hours, unsigned int& mins) {
    mins = minutes % 60;
    hours = minutes / 60;
}

void getLastShow(int n, unsigned int& maxHours, unsigned int& maxMins) {
    unsigned int maxMinutesEnd=0;
    for (int i = 0; i < n; i++) {
        unsigned int currentHours; unsigned int currentMinutes; unsigned int currentDuration;
        cin >> currentHours >> currentMinutes >> currentDuration;
        unsigned int currentEnd = endOfPermormenceInMinutes(currentHours, currentMinutes, currentDuration);

        if (currentEnd > maxMinutesEnd)
            maxMinutesEnd = currentEnd;
    }
    makeEndFromMinutesToHoursAndMinutes(maxMinutesEnd, maxHours, maxMins);
    cout << maxHours << " " << maxMins;
}


int main()
{
    int n;
    cin >> n;
    unsigned int maxHours = 0;
    unsigned int maxMins = 0;

    getLastShow(n, maxHours, maxMins);
}


#include <stdio.h>
#include <time.h>
#include <windows.h>
int main() {
    int alarm_hour, alarm_minute, alarm_second,i;
    time_t current_time;
    struct tm *time_info;
    printf("Enter alarm time (HH MM SS): ");
    scanf("%d %d %d", &alarm_hour, &alarm_minute, &alarm_second);
    printf("Alarm set for %02d:%02d:%02d\n", alarm_hour, alarm_minute, alarm_second);
    while (1) {
        time(&current_time);
        time_info = localtime(&current_time);
        int current_hour = time_info->tm_hour;
        int current_minute = time_info->tm_min;
        int current_second = time_info->tm_sec;
        printf("Current time: %02d:%02d:%02d\n", current_hour, current_minute, current_second);
        if ((current_hour > alarm_hour) ||
            (current_hour == alarm_hour && current_minute > alarm_minute) ||
            (current_hour == alarm_hour && current_minute == alarm_minute && current_second >= alarm_second)) {
            
            printf("\n? ALARM! Time's up!\n");
           for (i = 0; i < 10; i++) {
    		Beep(1000, 900);
    		Sleep(100);
			}
            break;
        }

        Sleep(1000);
    }

    return 0;
}


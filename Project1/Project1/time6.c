#include <stdio.h>
#include <time.h>

int calculate_hours_difference(int year1, int month1, int day1, int hour1, int year2, int month2, int day2, int hour2) {
    struct tm time1 = { 0 };
    struct tm time2 = { 0 };

    // Set the first time
    time1.tm_year = year1 - 1900;
    time1.tm_mon = month1 - 1;
    time1.tm_mday = day1;
    time1.tm_hour = hour1;

    // Set the second time
    time2.tm_year = year2 - 1900;
    time2.tm_mon = month2 - 1;
    time2.tm_mday = day2;
    time2.tm_hour = hour2;

    // Calculate the difference in seconds
    double seconds_difference = difftime(mktime(&time2), mktime(&time1));

    // Convert the difference to hours
    int hours_difference = seconds_difference / 3600;

    return hours_difference;
}

int main() {
    int year1, month1, day1, hour1;
    int year2, month2, day2, hour2;

    printf("Enter the first date and time (YYYY MM DD HH): ");
    scanf("%d %d %d %d", &year1, &month1, &day1, &hour1);

    printf("Enter the second date and time (YYYY MM DD HH): ");
    scanf("%d %d %d %d", &year2, &month2, &day2, &hour2);

    if (mktime(&(struct tm) { .tm_year = year1 - 1900, .tm_mon = month1 - 1, .tm_mday = day1, .tm_hour = hour1 }) <
        mktime(&(struct tm) { .tm_year = year2 - 1900, .tm_mon = month2 - 1, .tm_mday = day2, .tm_hour = hour2 })) {
        printf("The first date and time is earlier than the second one. Exiting...\n");
        return 0;
    }

    int hours_difference = calculate_hours_difference(year1, month1, day1, hour1, year2, month2, day2, hour2);

    printf("The difference between the two times is %d hours.\n", hours_difference);

    return 0;
}

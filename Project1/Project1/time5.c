#define _CRT_SECURE_NO_WARNINGS

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
	int year1, month1 = 12, day1 = 31, hour1 = 23;
	int year2, month2 = 1, day2 = 1, hour2 = 1;

	while (1) {

		printf("Enter the first year: ");
		scanf("%d", &year1);

		if (year1 = -1)break;

		printf("Enter the first month1: ");
		scanf("%d", &month1);

		printf("Enter the first day1: ");
		scanf("%d", &day1);

		printf("Enter the first hour1: ");
		scanf("%d", &hour1);

		printf("Enter the second year: ");
		scanf("%d", &year2);

		printf("Enter the second month2: ");
		scanf("%d", &month2);

		printf("Enter the second day2: ");
		scanf("%d", &day2);

		printf("Enter the second hour2: ");
		scanf("%d", &hour2);

		int hours_difference = calculate_hours_difference(year1, month1, day1, hour1, year2, month2, day2, hour2);

		printf("The difference between the two times is %d hours.\n", hours_difference);

	}

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int is_leap_year(int year) {
	return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int calculate_hours_difference(int year1, int month1, int day1, int hour1, int year2, int month2, int day2, int hour2) {
	int hours_difference = 0;

	while (year1 < year2 || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2) || (year1 == year2 && month1 == month2 && day1 == day2 && hour1 < hour2)) {
		hour1++;
		if (hour1 == 24) {
			hour1 = 0;
			day1++;
			if (day1 > days_in_month[month1 - 1] + (month1 == 2 && is_leap_year(year1))) {
				day1 = 1;
				month1++;
				if (month1 == 13) {
					month1 = 1;
					year1++;
				}
			}
		}
		hours_difference++;
	}

	return hours_difference;
}

int main() {
	int year1, month1, day1, hour1;
	int year2, month2, day2, hour2;

	while (1) {

		printf("Enter the “à‘ Œv date and time (YYYY MM DD HH): ");
		scanf("%d %d %d %d", &year1, &month1, &day1, &hour1);

		if (year1 == -1)break;

		printf("Enter the Á”ïŠúŒÀ date and time (YYYY MM DD HH): ");
		scanf("%d %d %d %d", &year2, &month2, &day2, &hour2);

		if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2) || (year1 == year2 && month1 == month2 && day1 == day2 && hour1 > hour2)) {
			printf("Á”ïŠúŒÀØ‚ê‚Å‚·...\n");
			continue;
		}

		int hours_difference = calculate_hours_difference(year1, month1, day1, hour1, year2, month2, day2, hour2);

		printf("The difference between the two times is %d hours.\n", hours_difference);
	}
	return 0;
}

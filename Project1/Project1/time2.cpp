#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 各月の日数
int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 年月日時を時間に変換
int convert_to_hours(int time) {
    int month = time / 10000;
    int day = (time % 10000) / 100;
    int hour = time % 100;

    int total_hours = 0;

    // 月を時間に変換
    for (int i = 0; i < month - 1; i++) {
        total_hours += days_in_month[i] * 24;
    }

    // 日を時間に変換
    total_hours += (day - 1) * 24;

    // 時を加算
    total_hours += hour;

    return total_hours;
}

int calculate_difference(int iExpirationDate, int iNeo7Time) {
    int difference = 0;
    int iExpirationDateHours = 0;
    int iNeo7TimeHours = 0;


    if (iExpirationDate > iNeo7Time) {
        //年越した
        iNeo7Time += 120000;
    }

    iExpirationDateHours = convert_to_hours(iExpirationDate);
    iNeo7TimeHours = convert_to_hours(iNeo7Time);

    difference = iNeo7TimeHours - iExpirationDateHours;
  
    
    return difference;
}

int main() {
    int time1 = 2023010100;  // YYYYMMDDHH形式での時間1
    int time2 = 2024010100;  // YYYYMMDDHH形式での時間2

    while (1) {

        printf("賞味期限を入力してください:");
        scanf("%d", &time1);

        if (time1 == -1)break;

        printf("Neo7の日付を入力してください:");
        scanf("%d", &time2);

        if (time2 == -1)break;

        int difference = calculate_difference(time1, time2);
        printf("The difference between the two times is %d hours.\n", difference);
    }
    return 0;
}
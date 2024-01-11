#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 閏年を判定する関数
// 1 = うるう年
int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    }
    else if (year % 100 == 0) {
        return 0;
    }
    else if (year % 4 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// 年と月からその月の日数を返す関数
int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// MMDDHH形式の時間を時間単位に変換する関数
int convertToHours(int year,int MMDDHH) {
    int time = MMDDHH;
    int month, day, hour;

    // 時間を取り出す
    hour = time % 100;
    time /= 100;

    // 日を取り出す
    day = time % 100;
    time /= 100;

    // 月を取り出す
    month = time % 100;
    time /= 100;

    // 年を取り出す
   // year = time;

    int totalHours = 0;

    // 年初からの経過月数を計算
    for (int m = 1; m < month; m++) {
        totalHours += daysInMonth(year, m) * 24;
    }

    // 月初からの経過日数を計算
    totalHours += (day - 1) * 24;

    // 日初からの経過時間を計算
    totalHours += hour;

    return totalHours;
}

void get() {

}

int main() {
    int neo7Timeyear, shomi, neo7Time;

    printf("年を入力してください: ");
    scanf("%d", &neo7Timeyear);

    printf("賞味期限 (MMDDHH形式)を入力してください: ");
    scanf("%d", &shomi);

    printf("Neo7時間 (MMDDHH形式) を入力してください: ");
    scanf("%d", &neo7Time);

    int hoursA = convertToHours(neo7Timeyear, shomi);
    int neo7TimeHours = convertToHours(neo7Timeyear,neo7Time);

    printf("賞味時間%d:Neo7時間%d \n",hoursA, neo7TimeHours);


    printf("時間Aと時間Bの差は %d 時間です。\n", abs(hoursA - neo7TimeHours));

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int calculate_difference(int time1, int time2) {
    int month1 = time1 / 10000;
    int day1 = (time1 % 10000) / 100;
    int hour1 = time1 % 100;

    int month2 = time2 / 10000;
    int day2 = (time2 % 10000) / 100;
    int hour2 = time2 % 100;

    // 仮定: 同じ月内での計算
    //if (month1 != month2) {
    //    printf("Error: The two times are not in the same month.\n");
    //    exit(1);
   // }

    int difference = (day2 - day1) * 24 + (hour2 - hour1);
    return difference;
}

int main() {
    int time1 = 12300;  // MMDDHH形式での時間1
    int time2 = 12312;  // MMDDHH形式での時間2

    while(1){

        printf("1つ目の日付を入力してください:");
        scanf("%d", &time1);

        if (time1 == -1)break;

        printf("2つ目の日付を入力してください:");
        scanf("%d", &time2);

        if (time2 == -1)break;

        int difference = calculate_difference(time1, time2);
        printf("The difference between the two times is %d hours.\n", difference);


    }
    return 0;
}
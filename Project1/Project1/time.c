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

    // ����: ���������ł̌v�Z
    //if (month1 != month2) {
    //    printf("Error: The two times are not in the same month.\n");
    //    exit(1);
   // }

    int difference = (day2 - day1) * 24 + (hour2 - hour1);
    return difference;
}

int main() {
    int time1 = 12300;  // MMDDHH�`���ł̎���1
    int time2 = 12312;  // MMDDHH�`���ł̎���2

    while(1){

        printf("1�ڂ̓��t����͂��Ă�������:");
        scanf("%d", &time1);

        if (time1 == -1)break;

        printf("2�ڂ̓��t����͂��Ă�������:");
        scanf("%d", &time2);

        if (time2 == -1)break;

        int difference = calculate_difference(time1, time2);
        printf("The difference between the two times is %d hours.\n", difference);


    }
    return 0;
}
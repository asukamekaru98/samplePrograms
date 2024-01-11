#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// �[�N�𔻒肷��֐�
// 1 = ���邤�N
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

// �N�ƌ����炻�̌��̓�����Ԃ��֐�
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

// MMDDHH�`���̎��Ԃ����ԒP�ʂɕϊ�����֐�
int convertToHours(int year,int MMDDHH) {
    int time = MMDDHH;
    int month, day, hour;

    // ���Ԃ����o��
    hour = time % 100;
    time /= 100;

    // �������o��
    day = time % 100;
    time /= 100;

    // �������o��
    month = time % 100;
    time /= 100;

    // �N�����o��
   // year = time;

    int totalHours = 0;

    // �N������̌o�ߌ������v�Z
    for (int m = 1; m < month; m++) {
        totalHours += daysInMonth(year, m) * 24;
    }

    // ��������̌o�ߓ������v�Z
    totalHours += (day - 1) * 24;

    // ��������̌o�ߎ��Ԃ��v�Z
    totalHours += hour;

    return totalHours;
}

void get() {

}

int main() {
    int neo7Timeyear, shomi, neo7Time;

    printf("�N����͂��Ă�������: ");
    scanf("%d", &neo7Timeyear);

    printf("�ܖ����� (MMDDHH�`��)����͂��Ă�������: ");
    scanf("%d", &shomi);

    printf("Neo7���� (MMDDHH�`��) ����͂��Ă�������: ");
    scanf("%d", &neo7Time);

    int hoursA = convertToHours(neo7Timeyear, shomi);
    int neo7TimeHours = convertToHours(neo7Timeyear,neo7Time);

    printf("�ܖ�����%d:Neo7����%d \n",hoursA, neo7TimeHours);


    printf("����A�Ǝ���B�̍��� %d ���Ԃł��B\n", abs(hoursA - neo7TimeHours));

    return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned char week;					/* days since Sunday - [0,6] */
    unsigned char year;					/* years since 2000 */
    unsigned char month;				/* months since January - [1,12] */
    unsigned char day;					/* day of the month - [1,31] */
    unsigned char hour;					/* hours since midnight - [0,23] */
    unsigned char minute;				/* minutes after the hour - [0,59] */
    unsigned char second;				/* seconds after the minute - [0,59] */
} TIME;

int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
unsigned char LeapYearTbl[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
unsigned char NormalYearTbl[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int IsLeapYear(unsigned short uhYear)
{
    if (uhYear < 2000) {
        uhYear += 2000;
    }

    if (((uhYear % 4) == 0) && ((uhYear % 400) != 0)) return 1;
    return 0;
}

unsigned int GetDaysBasedOn20000101(const TIME* pTime)
{
    unsigned char bYear, bMonth, bDay;
    unsigned int i, iDays = 0;
    unsigned char* pMonthDay;

    bYear = pTime->year;
    bMonth = pTime->month;
    bDay = pTime->day;

    iDays += bYear * 365 + (bYear + 3) / 4;	// add year day based on 2000

    if (!IsLeapYear(bYear)) {
        pMonthDay = NormalYearTbl;		// month day table during to year
    }
    else {
        pMonthDay = LeapYearTbl;
    }

    for (i = 1;i < bMonth;i++)
    {
        iDays += *pMonthDay++;			// add month day based on Jan
    }

    iDays += bDay - 1;					// add day based on 1st

    return iDays;
}

static int CalcSecondDiff(TIME tTimeL, TIME tTimeR)
{
    int iRetDiff = 0;

    int iTimeL = GetDaysBasedOn20000101(&tTimeL);
    int iTimeR = GetDaysBasedOn20000101(&tTimeR);

    iRetDiff = (iTimeL - iTimeR) * 24 + tTimeL.hour - tTimeR.hour;	//ŽžŠÔ·ŒvŽZ
    iRetDiff = iRetDiff * 60 + tTimeL.minute - tTimeR.minute;		//•ª·ŒvŽZ
    iRetDiff = iRetDiff * 60 + tTimeL.second - tTimeR.second;		//•b·ŒvŽZ

    return iRetDiff;
}

int main()
{
    TIME tHistoryExpTime = { 0,24,4,23,23,59,59 };
    TIME tCurrentTime = { 0,24,4,24,0,0,0 };


    int timediff;

    timediff = CalcSecondDiff(tHistoryExpTime, tCurrentTime);
    printf("%d•b\n", timediff);

  

    return 0;
}
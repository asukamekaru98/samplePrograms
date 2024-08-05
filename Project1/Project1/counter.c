#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	const int iPrintNum = 20;
	const int iCutInterval = 10;
	int iFix, iPrint;

	for (int iCnt = 0;iCnt <= iPrintNum; iCnt++) {

		if (iCnt == 0) {
			iPrint = 0;
		}
		else {
			iFix = iCnt % iCutInterval;
			iPrint = (iFix == 0) ? iCutInterval : iFix;
		}

		printf("%d\n", iPrint);
	}
}



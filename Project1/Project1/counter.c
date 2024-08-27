#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void Cutting(const int iCutInterval, int* pCutCounter)
{
	if (iCutInterval == *pCutCounter) {
		printf("カット開始！\n");
		*pCutCounter = 0; //カウンター初期化
	}
}


void charPrint(int iAllPage,int iPage)
{
	printf("合計%d枚のうち、%d枚印刷完了\n", iAllPage,iPage);
}

int main()
{
	const int iAllPrintNum = 20;			//合計印刷枚数
	const int iCutInterval = 10;		//カットインターバル
	int iFix, iPrint,iCutterCounter = 0;


	for (int iPrintCnt = 0;iPrintCnt <= iAllPrintNum; iPrintCnt++) {

	
		//if (iCnt == 0) {
		//	iPrint = 0;
		//}
		//else {
		//	iFix = iCnt % iCutInterval + 1;
		//	iPrint = (iFix == 0) ? iCutInterval : iFix;
		//}
		iCutterCounter = iPrintCnt % iCutInterval;
		

		charPrint(iAllPrintNum, iPrintCnt);
		
		printf("カットカウンター：%d\n", iCutterCounter);
		Cutting(iCutInterval, &iCutterCounter);
		printf("カットカウンター：%d\n", iCutterCounter);
		printf("----------------------------------\n", iCutterCounter);
	}
}



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void Cutting(const int iCutInterval, int* pCutCounter)
{
	if (iCutInterval == *pCutCounter) {
		printf("�J�b�g�J�n�I\n");
		*pCutCounter = 0; //�J�E���^�[������
	}
}


void charPrint(int iAllPage,int iPage)
{
	printf("���v%d���̂����A%d���������\n", iAllPage,iPage);
}

int main()
{
	const int iAllPrintNum = 20;			//���v�������
	const int iCutInterval = 10;		//�J�b�g�C���^�[�o��
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
		
		printf("�J�b�g�J�E���^�[�F%d\n", iCutterCounter);
		Cutting(iCutInterval, &iCutterCounter);
		printf("�J�b�g�J�E���^�[�F%d\n", iCutterCounter);
		printf("----------------------------------\n", iCutterCounter);
	}
}



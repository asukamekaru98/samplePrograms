#include<stdio.h>

#define intdown(x,y)	(((x)/(y))*(y))
#define intup(x,y)		((((x)+(y)-1)/(y))*(y))

int main()
{
	unsigned int ucCurrentCategoryIndex;
	unsigned int uiMaxCategoryOnePage = 2;	//1do

	for (ucCurrentCategoryIndex = 1; ucCurrentCategoryIndex <= 8; ucCurrentCategoryIndex++) {
		int j = intdown((ucCurrentCategoryIndex - 1), uiMaxCategoryOnePage) + 1;
		int k = intdown((ucCurrentCategoryIndex - 1), uiMaxCategoryOnePage) + uiMaxCategoryOnePage;

		printf("���݃y�[�W%d�ŁA�ő�^�u��%d�̂Ƃ��A���[��%d�A�E�[��%d\n", ucCurrentCategoryIndex, uiMaxCategoryOnePage,j,k);

	}

	uiMaxCategoryOnePage = 4;

	for (ucCurrentCategoryIndex = 1; ucCurrentCategoryIndex <= 8; ucCurrentCategoryIndex++) {
		int j = intdown((ucCurrentCategoryIndex - 1), uiMaxCategoryOnePage) + 1;
		int k = intdown((ucCurrentCategoryIndex - 1), uiMaxCategoryOnePage) + uiMaxCategoryOnePage;

		printf("���݃y�[�W%d�ŁA�ő�^�u��%d�̂Ƃ��A���[��%d�A�E�[��%d\n", ucCurrentCategoryIndex, uiMaxCategoryOnePage, j, k);

	}

}
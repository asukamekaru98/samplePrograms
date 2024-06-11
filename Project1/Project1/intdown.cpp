#include<stdio.h>

#define intdown(x,y)	(((x)/(y))*(y))

int main()
{
	unsigned int ucCurrentCategoryIndex = 5;
	unsigned int uiMaxCategoryOnePage = 4;

	for (int i = 1; i <= 8; i++) {
		int j = intdown((ucCurrentCategoryIndex - 1), uiMaxCategoryOnePage) + 1;

		printf("%d", j);
	}
}
#include <string.h>
#include<stdio.h>

#define MAX 10

// ‹ó”’s‚ğíœ‚µ‚ÄA‹l‚ß‚é
void TrimEmptyLines(int* p)
{
	int i, j;

	for (i = 0;i < MAX;i++) {
		if (p[i] != 0) {
			continue;
		}

		for (j = i + 1;j < MAX;j++) {
			if (p[j] == 0) {
				continue;
			}

			p[i] = p[j];
			p[j] =  0;
			break;
		}

	}

	for (i = 0;i < MAX;i++) {
		printf("%d\n", p[i]);
	}
	
}

int main()
{
	int iArray[MAX] = { 1,2,3,0,0,6,7,8,0,10 };

	TrimEmptyLines(iArray);
}
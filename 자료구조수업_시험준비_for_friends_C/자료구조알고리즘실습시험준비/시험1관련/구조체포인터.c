#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;
};

void main() {
	int i, max = 0, index = 0;
	struct employee team[4] = {
		{ "����ȣ", 2014, 4200 },
		{ "���ѿ�", 2015, 3300 },
		{ "�̻��", 2015, 3500 },
		{ "�̻��", 2016, 2900 }
	}; 
	struct employee *ptr;
	ptr = team;

	for (i = 0; i < 4; i++)
	{
		if ((ptr + i)->pay > max)
		{
			max = (ptr + i)->pay;
			index = i;
		}
	}
	printf("\n\n���� ū ������ : %d \n\n", max);
	printf("\n\n���� ������ ���� ��� �̸� : %s \n\n", (ptr+index) -> name);


	for (i = 0; i<4; i++) {
		printf("\n �̸� : %s", team[i].name);
		printf("\n �Ի� : %d", team[i].year);
		printf("\n ���� : %d \n", team[i].pay);
	}
	getchar();

	/*char *ptrArray[5];
	char **ptrptr;
	int i, max = 0,index = 0;

	ptrptr = ptrArray;

	ptrArray[0] = "Korea";
	ptrArray[1] = "Polytechic";
	ptrArray[2] = "University";
	ptrArray[3] = "Apppppppppppppple";
	ptrArray[4] = "Pi";
	
	for(i = 0; i < 5; i++)
	{
		if (strlen(*(ptrptr + i)) > max)
		{
			max = strlen(*(ptrptr + i));
			index = i;
		}
	}
	printf("���� �� ���� : %d\n", max);
	printf("���� �� �ܾ� : %s\n", *(ptrptr + index));*/
}
#include<stdio.h>
#include<string.h>

void main()
{
	int i,j;
	int k=0;
	char input[100];
	char output[5][16];

	printf(" �ܾ� 5���� ����� �����Ͽ� �� ���ڿ��� �Է��Ͻÿ�(Ư������ ���� ����) : \n");
	printf(" ��: Apple Banana Watermelon Love Great!! \n\n");

    gets(input);

	for(i=0; i<5; i++)
	{
		for (j=0; j<16; j++)
		{
		  if((input[k] == ' ') || (input[k] == '\0')) // input[k]�� ��ĭ�̰ų� �ΰ��̴�?
		  { output[i][j] = '\0'; k++; break;} // output[i][���ڼ�] 
		  else if (input[k] == ' ' && input[k + 1] != ' ' && input[k + 1] != NULL)
		  { output[i][j] = input[k]; } 
		  else
		  { output[i][j] = input[k]; k++; }
		}
	}
		printf("\n\n");

		for (i=0; i<5; i++)
			printf("%s\n", output[i]);

		printf("\n\n");
	
   i=0;
   for(j=0; j<5; j++)
         if(strlen(output[i]) < strlen(output[j]))
            i=j;
   printf("\n ���� �� ���ڿ���? : %s", output[i]);

   i=0;
   for(j=0; j<5; j++)
         if(strlen(output[i]) > strlen(output[j]))
            i=j;
   printf("\n ���� ª�� ���ڿ���? : %s\n", output[i]);
   

}

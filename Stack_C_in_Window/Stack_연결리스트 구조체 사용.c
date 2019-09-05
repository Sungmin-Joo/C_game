#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef char element;		// ���� ����(element)�� �ڷ����� int�� ���� 
int cnt = 0;
typedef struct  stackNode {	// ������ ��带 ����ü�� ����
	element data;
	struct stackNode *link;
} stackNode;

stackNode* top;				// ������ top ��带 �����ϱ� ���� ������ top ����

							// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;     // ���� ��带 top�� ���� ����
	top = temp;           // top ��ġ�� ���� ���� �̵�
	cnt++;
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {		// ������ ���� ����Ʈ�� ���
		//printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);	
		cnt--;		// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
	if (top == NULL) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		return(top->data);  // ���� top�� ���� ��ȯ
	}
}

// ������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%c ", p->data);
		p = p->link;
	}
	printf("] ");
}

void view_stack()
{
	int flag = 10;
	system("cls");
	stackNode* temp;
	temp = top;
	printf("	|    stack    |\n");
	printf("	|-------------|\n");
	for (flag; flag > cnt; flag--)
		printf("	|             |\n");

	while (temp != NULL)
	{
		printf("	|      %c      |\n", temp->data);
		temp = temp->link;
		flag--;
	}
	printf("	|-------------|\n");
}

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}

void main(void) {
	char n;
	system("COLOR 02");
	system("mode con cols=45 lines=23");
	element item, temp;
	top = NULL;
	while (1)
	{
		view_stack();
		printf("%30s", "* 1. Push mode.       \n");
		printf("%30s", "* 2. Pop mode.        \n");
		printf("%30s", "* 3. Exit the program.\n");
		printf("\n%24s", "Select number : ");
		scanf("%c", &n);

		if (n == '1')
		{
			while (1)
			{
				view_stack();
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Push data : ");
				scanf("%c", &n);

				if (n == '/')
				{
					break;
				}
				else if ((n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
				{
					if (cnt == 10)
					{
						printf("\n\n%35s", "The stack is full....");
						delay(500);
					}
					else
						push(n);
				}
			}
		}
		else if (n == '2')
		{
			while (getchar() != '\n');
			while (1)
			{
				view_stack();
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Press enter to pop : ");
				scanf("%c", &n);

				if (n == '/')
				{
					break;
				}
				else
				{
					temp = pop();
					if (temp == 0)
					{
						printf("\n\n%39s", "The stack is emty....");
						delay(1000);
					}
					else
					{
						printf("\n\n%39s", "Output data : ");
						printf("%c", temp);
						delay(1000);
					}
				}
			}
		}
		else if (n == '3')
			break;
	}
}
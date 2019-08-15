#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>

typedef char element;      // ���� ����(element)�� �ڷ����� int�� ����
typedef char q_element;     // ���� ť ����(q_element)�� �ڷ����� char�� ����

typedef struct  stackNode {   // ������ ��带 ����ü�� ����
	element data;
	struct stackNode *link;
} stackNode, stackNode2;

stackNode* top;            // ������ top ��带 �����ϱ� ���� ������ top ����

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
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {      // ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {               // ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;   // top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);         // ������ ����� �޸� ��ȯ
		return item;      // ������ ���� ��ȯ
	}
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
	if (top == NULL) {      // ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {               // ������ ���� ����Ʈ�� �ƴ� ���
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


typedef struct QNode {    // ���� ť�� ��带 ����ü�� ����
	q_element data;
	struct QNode *link;
} QNode;

typedef struct {		// ���� ť���� ����ϴ� ������ front�� rear�� ����ü�� ����
	QNode *front, *rear;
} LQueueType;

// ���� ���� ť�� �����ϴ� ����
LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty_q(LQueueType *LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(LQueueType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// ���� ���� ť�� ���� ������ ���
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// ���� ���� ť�� ���� ���°� �ƴ� ���
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// ���� ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
q_element deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	q_element item;
	if (isEmpty_q(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

// ���� ť���� ���Ҹ� �˻��ϴ� ����
q_element peek_q(LQueueType *LQ) {
	q_element item;
	if (isEmpty_q(LQ)) return 0;
	else {
		item = LQ->front->data;
		return item;
	}
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printLQ(LQueueType *LQ) {
	QNode *temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

char switch_decimal_to_16_notation(int A)
{
	switch (A)
	{
	case 15:
		return 'F';
		break;
	case 14:
		return 'E';
		break;
	case 13:
		return 'D';
		break;
	case 12:
		return 'C';
		break;
	case 11:
		return 'B';
		break;
	case 10:
		return 'A';
		break;
	default:
		return '0' + A;
		break;
	}
}

void main(void) {
	LQueueType *LQ = createLinkedQueue();
	q_element data;
	element item;
	int i, count = 0, decimal, part, q_count = 0;
	char temp[4];

	top = NULL;
	printf("10������ �Է��ϼ���~ : ");
	scanf("%d", &decimal);
	while (1)
	{
		if (decimal / 2)
		{
			push((decimal % 2) + 0x30);
			decimal /= 2;
		}
		else
		{
			push(decimal + 0x30);
			break;
		}
	}
	printStack();
	putchar('\n');
	printf("2���� ��� �Դϴ�. : ");
	while (!isEmpty())
	{
		data = pop();
		putchar(data);
		enQueue(LQ, data);
		q_count++;
	}
	enQueue(LQ, '\0');
	putchar('\n');
	printLQ(LQ);

	
	decimal = 0;
	for (i = (q_count % 4) - 1; i >= 0; i--)
	{
		data = deQueue(LQ);
		q_count--;
		if (data == '1')
		{
			switch (i)
			{
			case 2:
				decimal += 4;
				break;
			case 1:
				decimal += 2;
				break;
			case 0:
				decimal += 1;
				break;
			default:
				break;
			}
		}
	}
	putchar('\n');
	printf("16������ ��ȯ�� �� �Դϴ�. : ");
	putchar(switch_decimal_to_16_notation(decimal));
	
	while (1)
	{	
		decimal = 0;
		for (i = 3; i >= 0; i--)
		{
			data = deQueue(LQ);
			q_count--;
			if (data == '1')
			{
				switch (i)
				{
				case 3:
					decimal += 8;
					break;
				case 2:
					decimal += 4;
					break;
				case 1:
					decimal += 2;
					break;
				case 0:
					decimal += 1;
					break;
				default:
					break;
				}
			}
		}
		putchar(switch_decimal_to_16_notation(decimal));
		if (q_count == 0)
			break;
	}
	putchar('\n');
}
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

void main(void) {
	LQueueType *LQ = createLinkedQueue();  // ���� ť ����
	q_element data;
	element item;
	int i, count = 1, len_count, max, min;
	char *str = "Korea Polytechnic University Love Me";
	top = NULL;
	printLQ(LQ);
	printf("\n");
	for (i = 0; i < strlen(str); i++)   //�������� KOREA POLY...Enqueue�ϴ� �����ΰŰ���
	{
		if (str[i] == ' ')
			count++;
		enQueue(LQ, str[i]);
	}
	printLQ(LQ);
	enQueue(LQ, '\0');

	//push('\0');
	max = 0;
	min = strlen(str);
	for (i = 0; i < count; i++)
	{
		len_count = 0;
		while (1)
		{
			data = deQueue(LQ);
			if (data == ' ' || data == '\0')
				break;
			push(data);
			len_count++;
		}
		if (len_count > max)
			max = len_count;
		if (len_count < min)
			min = len_count;
		push(' ');
	}
	pop(); //�� �� �ΰ� ����
	printf("\n");
	printf("\n");
	printf("\n");
	//printLQ(LQ);
	//printf("\n"); ť�� ��� Ȯ��.
	printf("���� �� ���� = %d\n", max);
	printf("���� ª�� ���� = %d\n", min);
	printStack();
	printf("\n");
	printf("\n");
	for (i = 0; i < count; i++)
	{
		printf("%d. �ܾ� �Ųٷ� : ", i + 1);
		while (1)
		{
			item = pop();
			enQueue(LQ, item);
			if (item == ' ' || item == '\0' || isEmpty())
			{
				while (1)
				{
					data = deQueue(LQ);
					if(data <= 'z' && data >= 'a')
						putchar(data - 0x20);
					else if(data <= 'Z' && data >= 'A')
						putchar(data + 0x20);
					if (data == ' ' || data == '\0')
						break;
				}
				break;
			}
		}
		putchar('\n');
	}

}
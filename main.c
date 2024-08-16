#include <stdio.h>
#include <stdlib.h>

#define ADD 1
#define REMOVE 2
#define CLEAR 3
#define PRINT 4
#define EXIT 5

typedef struct Queue{
	char data;
	struct Queue* next;
} Queue;


// Прототипи усіх задіяних функцій
Queue* createNode(char);
void insert(Queue**, char);
void printQueue(Queue*);
void deleteQueue(Queue**);
void deleteElement(Queue**);
void cleanBuffer(void);
void clearConsole(void);
// Кінець прототипів


int main(void){
Queue* queue = 0;
short int choice = 0;
while (choice != EXIT){ // main loop in the program
	printf("Enter your choice:\n\t1 to add an item to the queue\n\t2 to remove an item from the queue\n\t"
	"3 to clear console\n\t4 to print the queue\n\t5 to end\n? ");
	while (scanf("%hd", &choice) != 1) {
		printf("Entered incorrect value! Please, try again\n? ");
		cleanBuffer();
	}
	char ch;
	if (ADD == choice){
		while (1){
			printf("Enter a character(A-Z either a-z): ");
			cleanBuffer();
			ch = getchar();
			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) break;
		}
		insert(&queue, ch);
		printQueue(queue);
	}
	else if (REMOVE == choice){
		if (queue) deleteElement(&queue);
		if (!queue) puts("Queue is empty.");
		else printQueue(queue);
	}
	else if (CLEAR == choice) clearConsole();
	else if (PRINT == choice) printQueue(queue);
	else if (EXIT == choice) puts("End of run.");
	else puts("Invalid choice.");
}
deleteQueue(&queue);
return 0;
}

Queue* createNode(char ch){
Queue* head = (Queue*)malloc(sizeof(Queue));
if (!head) {perror("Error with allocation memory! Exit..."); return NULL;}
head->data = ch; head->next = 0;
return head;
}

void insert(Queue** head, char ch){
Queue* temp = createNode(ch);
if (NULL == *head) {*head = temp; return;}
Queue* curr = *head;
while (curr->next != NULL) curr = curr->next;
curr->next = temp;
}

void printQueue(Queue* head){
puts("The queue is:");
while (head != NULL){
	printf("%c --> ", head->data);
	head = head->next;
}
puts("NULL");
}

void deleteQueue(Queue** head){
Queue* temp = 0;
while ((temp = *head) != NULL) {
*head = temp->next;
free(temp);
}
}

void deleteElement(Queue** head){
Queue* temp = *head;
*head = temp->next;
free(temp);
}

void cleanBuffer(void){
int c;
while ((c = getchar()) != EOF && c != '\n');
}

void clearConsole(void){
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
}


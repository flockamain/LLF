#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

void printList(node *);
void insertOrder(node *&, int);
void removeDuplicates(node *);
void betweenNumbers(node *, int, int);
void reverseOrder(node *);

int main() {

	node *header = NULL;		// empty linked list

	insertOrder(header, 33);
	printList(header);
	cout << endl;

	insertOrder(header, 17);
	printList(header);
	cout << endl;

	insertOrder(header, 49);
	printList(header);
	cout << endl;

	insertOrder(header, 22);
	printList(header);
	cout << endl;

	insertOrder(header, 22);
	printList(header);
	cout << endl;

	insertOrder(header, 49);
	printList(header);
	cout << endl;

	insertOrder(header, 17);
	printList(header);
	cout << endl;

	insertOrder(header, 21);
	printList(header);
	cout << endl;

	insertOrder(header, 64);
	printList(header);
	cout << endl;

	insertOrder(header, 61);
	printList(header);
	cout << endl;

	insertOrder(header, 77);
	printList(header);
	cout << endl;

	insertOrder(header, 41);
	printList(header);
	cout << endl;

	insertOrder(header, 31);
	printList(header);
	cout << endl;

	insertOrder(header, 20);
	printList(header);
	cout << endl;		//all numbers have been inserted

	cout << endl;

	removeDuplicates(header);		//removing duplicates from list

	printList(header);

	cout << endl;

	betweenNumbers(header, 18, 42);		//demonstrating you can display numbers between numbers that don't exist in the list

	cout << endl;

	cout << "reverse order is: ";

	reverseOrder(header);

	cout << endl;

	



	system("PAUSE");
	return 0;
}

void removeDuplicates(node * header)
{
	cout << "removing duplicates" << endl;

	node *p, *test, *sec;
	
	for (p = header; p != NULL && p->next != NULL; p = p->next)
	{
		for (test = p; test->next != NULL; test = test->next)
		{
			if (p->data == test->next->data)
			{
				sec = test->next;
				test->next = test->next->next;
				delete sec;
			}
		}
	}
}

void betweenNumbers(node * header, int x, int y) {

	node *p;

	for (p = header; p != NULL && x >= p->data; p = p->next)
		;
	cout << endl;
	cout << "The values between " << x << " and " << y << " are: " << endl;
	for (p = p; p != NULL && p->data < y; p = p->next) {
		cout << p->data << endl;
	}


}

void reverseOrder(node *header) {
	node *one = NULL;
	node *two = header;
	node *three = NULL;

	while (two != NULL) {
		three = two->next;
		two->next = one;
		one = two;
		two = three;
	}
	header = one;
	printList(header);
}

void insertOrder(node *&header, int value)
{
	node *p, *prev;

	for (p = header, prev = NULL; p != NULL && value > p->data; prev = p, p = p->next)
		;

	// create new node
	node *insertNode = new node;

	// set data
	insertNode->data = value;

	// point new node at next
	insertNode->next = p;

	if (prev != NULL)
		// point previous pointer at new node
		prev->next = insertNode;
	else   // it is at front of list (special case)
		header = insertNode;

	
}

void printList(node *header)
{
	for (node *p = header; p != NULL; p = p->next) {
		cout << p->data << ", ";
	}
	
}

//test output:

/*
33,
17, 33,
17, 33, 49,
17, 22, 33, 49,
17, 22, 22, 33, 49,
17, 22, 22, 33, 49, 49,
17, 17, 22, 22, 33, 49, 49,
17, 17, 21, 22, 22, 33, 49, 49,
17, 17, 21, 22, 22, 33, 49, 49, 64,
17, 17, 21, 22, 22, 33, 49, 49, 61, 64,
17, 17, 21, 22, 22, 33, 49, 49, 61, 64, 77,
17, 17, 21, 22, 22, 33, 41, 49, 49, 61, 64, 77,
17, 17, 21, 22, 22, 31, 33, 41, 49, 49, 61, 64, 77,
17, 17, 20, 21, 22, 22, 31, 33, 41, 49, 49, 61, 64, 77,

removing duplicates
17, 20, 21, 22, 31, 33, 41, 49, 61, 64, 77,

The values between 18 and 42 are:
20
21
22
31
33
41

reverse order is: 77, 64, 61, 49, 41, 33, 31, 22, 21, 20, 17,
Press any key to continue . . .*/
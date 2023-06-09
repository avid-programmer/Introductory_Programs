#include <iostream>

struct node 
{
	int data;
	struct node *next;

	node(int newData) : data(newData), next(nullptr) { }
};

int length(node *head) 
{
	if (head == nullptr) 
	{
		return 0;
	}

	else 
	{
		return 1 + length(head->next);
	}
}


int main()
{
	// Sample test case
	node *head = new node(2);
	head->next = new node(4);
	head->next->next = new node(5);
	
	std::cout << "Length of linked list: " << length(head) << "\n";
}

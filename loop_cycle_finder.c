#include <stdlib.h>
#include <stdio.h>

 typedef struct Node
{
	int		x;
	struct Node* next;
} Node;

void	check_leaks();
void	deallocate_list(Node **root);
void	insert_end(Node **root, int value);

int	has_loops(Node *root)
{
	Node	*slow;
	Node	*fast;

	slow = root;
	fast = root;
	while (slow != NULL && fast != NULL && fast -> next != NULL)
	{
		slow = slow-> next;
		fast = fast -> next -> next;

		if (slow == fast)
			return (1);
	}
	return (0);
}

int		main()
{
	Node *root = NULL; //if list is empty
	
	insert_end(&root, 16);
	insert_end(&root, 15);
	insert_end(&root, 14);
	insert_end(&root, 13);
	insert_end(&root, 12);
	insert_end(&root, 11);
	
	root -> next -> next -> next -> next -> next -> next = root -> next;

	if (has_loops(root) == 1)
	{
		printf("Linked list has a loop\n");
		return (1);
	}
	Node *curr = root;
	while (curr != NULL)
	{
		printf("%d\n", curr -> x);
		curr = curr -> next;
	}
	//deallocate_list(&root);
	check_leaks();
	return (0);
}
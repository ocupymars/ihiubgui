#include <stdlib.h>
#include <stdio.h>

 typedef struct Node
{
	int		x;
	struct Node* next;
} Node;

void	check_leaks();

void	deallocate_list(Node **root);

void	insert_beginning(Node **root, int value)
{
	Node	*new_node = malloc (sizeof(Node));
	if (new_node == NULL)
	{
		exit (3);
	}
	new_node -> x = value;
	new_node -> next = *root;
	*root = new_node;
}

int		main()
{
	Node *root = NULL; //if list is empty
	
	insert_beginning(&root, 12);
	insert_beginning(&root, 12);
	insert_beginning(&root, 12);

	Node *curr = root;
	while (curr != NULL)
	{
		printf("%d\n", curr -> x);
		curr = curr -> next;
	}

	deallocate_list(&root);
	check_leaks();
	return (0);
}
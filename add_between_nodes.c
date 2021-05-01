#include <stdlib.h>
#include <stdio.h>

 typedef struct Node
{
	int		x;
	struct Node* next;
} Node;

void	check_leaks();

void	deallocate_list(Node **root);

void	insert_beginning(Node **root, int value);

void	insert_end(Node **root, int value);

void	insert_after_node(Node *node, int value)
{
	Node *new_node =  malloc (sizeof(Node));
	if (new_node == NULL)
		exit (4);
	new_node -> x = value;
	new_node -> next = node -> next;
	node -> next = new_node;
}

int		main()
{
	Node *root = NULL; //if list is empty
	
	insert_end(&root, 15);
	insert_end(&root, 13);
	insert_end(&root, 14);

	insert_after_node(root, 12);
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
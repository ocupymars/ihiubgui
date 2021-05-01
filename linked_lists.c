#include <stdlib.h>
#include <stdio.h>

 typedef struct Node
{
	int		x;
	struct Node* next;
} Node;

void	check_leaks();

void	deallocate_list(Node **root)
{
	Node	*curr = *root;
	while (curr != NULL)
	{
		Node	*aux = curr;
		curr = curr -> next;
		free (aux);
	}
	*root = NULL;
}

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

void	insert_after_node(Node *node, int value)
{
	Node *new_node =  malloc (sizeof(Node));
	if (new_node == NULL)
		exit (4);
	new_node -> x = value;
	new_node -> next = node -> next;
	node -> next = new_node;
}

void	insert_end(Node **root, int value)
{
	Node *new_node = malloc (sizeof(Node));
	if (new_node ==  NULL)
		exit(1);
	new_node -> next = NULL;
	new_node -> x = value;

	if (*root == NULL)
	{
		*root = new_node;
		return;
	}
	Node *curr = *root;
	while (curr -> next != NULL)
	{
		curr = curr -> next;
	}
	curr -> next = new_node;
}

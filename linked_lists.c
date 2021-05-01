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
	Node	*aux;
	Node	*curr;
	
	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr -> next;
		free (aux);
	}
	*root = NULL;
}

void	insert_beginning(Node **root, int value)
{
	Node	*new_node;
	
	new_node = malloc (sizeof(Node));
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
	Node	*new_node;
	
	new_node =  malloc (sizeof(Node));
	if (new_node == NULL)
		exit (4);
	new_node -> x = value;
	new_node -> next = node -> next;
	node -> next = new_node;
}

void	insert_sorted(Node **root, int value)
{
	Node	*curr;

	if (*root == NULL || (*root) -> x <= value)  
	{
		insert_beginning(root, value);
		return ;
	}
	curr = *root;
	while (curr -> next != NULL)
	{
		if (curr -> next -> x <= value)
			break ;
		curr = curr -> next;
	}
	insert_after_node(curr, value);
}

void	insert_end(Node **root, int value)
{
	Node	*curr;
	Node	*new_node;
	
	new_node = malloc (sizeof(Node));
	if (new_node ==  NULL)
		exit(1);
	new_node -> next = NULL;
	new_node -> x = value;
	if (*root == NULL)
	{
		*root = new_node;
		return;
	}
	curr = *root;
	while (curr -> next != NULL)
	{
		curr = curr -> next;
	}
	curr -> next = new_node;
}

void	remove_element(Node **root, int value)
{	
	Node	*to_remove;
	Node	*curr;

	if (*root == NULL)
		return;
	if ((*root) -> x == value)
	{
		to_remove = *root;
		*root = (*root) -> next;
		free(to_remove);
		return ;
	}
	curr = *root;
	while (curr -> next !=NULL)
	{
		curr = curr -> next;
		if (curr -> next -> x == value)
		{
			to_remove = curr -> next;
			curr -> next = curr -> next -> next;
			free(to_remove);
			return ;
		}
	}
}
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

void	reverse_list(Node **root)
{
	Node	*prev;
	Node	*curr;
	Node	*after;

	prev = NULL;
	curr = *root;
	while (curr != NULL)
	{
		after = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = after;	
	}
	*root = prev;
}

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

int	count(Node *root)
{
	Node	*curr;
	int		c;

	c = 0;
	curr = root;
	while (curr != NULL)
	{
		curr = curr -> next;
		c++;
	}
	return (c);
}

int	count_recursive(Node *node)
{
	if (node == NULL)
		return (0);
	return (1 + count_recursive(node -> next));
}

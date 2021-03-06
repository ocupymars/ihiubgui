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
void	insert_after_node(Node *node, int value);
void	insert_end(Node **root, int value);
void	insert_sorted(Node **root, int value);
void	remove_element(Node **root, int value);

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

int		main()
{
	Node *root = NULL; //if list is empty
	
	insert_end(&root, 15);
	insert_end(&root, 14);
	insert_end(&root, 12);
	insert_sorted(&root, 13);
	reverse_list(&root);

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
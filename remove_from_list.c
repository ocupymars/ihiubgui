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

int		main()
{
	Node *root = NULL; //if list is empty
	
	insert_end(&root, 15);
	insert_end(&root, 14);
	insert_end(&root, 12);
	insert_sorted(&root, 13);
	remove_element(&root, 12);
	remove_element(&root, 15);
	remove_element(&root, 14);
	remove_element(&root, 13);

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
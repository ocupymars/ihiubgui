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

void	insert_sorted(Node **root, int value)
{
	if (*root == NULL || (*root) -> x <= value)  
	{
		insert_beginning(root, value);
		return ;
	}
    Node	*curr;

	curr = *root;
	while (curr -> next != NULL)
	{
		if (curr -> next -> x <= value)
			break ;
		curr = curr -> next;
	}
	insert_after_node(curr, value);
}

int		main()
{
	Node *root = NULL; //if list is empty
	
	insert_end(&root, 15);
	insert_end(&root, 14);
	insert_end(&root, 12);

	insert_sorted(&root, 13);
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
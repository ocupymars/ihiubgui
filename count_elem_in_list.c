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

int		main()
{
	Node *root = NULL; //if list is empty
	
	insert_end(&root, 16);
	insert_end(&root, 15);
	insert_end(&root, 14);
	insert_end(&root, 13);
	insert_end(&root, 12);
	insert_end(&root, 11);

	printf("Linked list has %d elements\n", count_recursive(root));
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
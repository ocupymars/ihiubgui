#include <stdlib.h>
#include <stdio.h>

 typedef struct Node
{
	int		x;
	struct Node* next;
} Node;

void	insert_end(Node **root, int value)
{
	Node* new_node = malloc (sizeof(Node));
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

int		main()
{
	Node *root = NULL; //if list is empty
	/*Node *root = malloc (sizeof(Node));
	if (root == NULL)
		exit(2);
	root->x = 15;
	root->next = NULL;
	*/
	insert_end(&root, -2);
	insert_end(&root, 123);

	Node *curr = root;
	while (curr != NULL)
	{
		printf("%d\n", curr -> x);
		curr = curr -> next;
	}
}
#include <stdlib.h>
#include <stdio.h>

 typedef struct Node
{
	int		x;
	struct Node* next;
} Node;

int		main()
{
	Node root;
	root.x = 15;
	root.next = malloc(sizeof(Node));
	root.next->x = -3;
	root.next->next = malloc(sizeof(Node));
	root.next->next->x = 22;
	root.next->next->next = NULL;

	/*Node* curr = &root;
	while (curr != NULL)
	{
		printf("%d\n", curr -> x);
		curr = curr -> next;
	}*/

	for (Node* curr = &root; curr != NULL; curr = curr->next)
	{
		printf("%d\n", curr -> x);	
	}
	free(root.next);
	return (0);
}

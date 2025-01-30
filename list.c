// Linked List Functions

#include <stdio.h>
#include <stdlib.h>

// Structure Node
struct node
{
	int info;
	struct node *next;
};
struct node *start = NULL;

// Functions Initializations
void create();
void display();
void insert_first(int ele);
void insert_last(int ele);
void insert_after_node(int ele, int key);
void insert_before_node(int key, int ele);
void insert_specific_position(int pos, int ele);
void delete_first();
void delete_last();
void delete_after_given_node(int key);
void delete_before_given_node(int key);
void delete_specific_position(int pos);
void delete_any_node_with_key(int key);

// Main Functions
int main()
{
	printf("\nLinked List Operations\n");
	printf("Create A Linked List\n");
	create();
	display();
	printf("\n");

	// Menu Driven Options
	int choice, ele, key, pos;
	while (1)
	{
		printf("\n0 - Exit The Program");
		printf("\n1 - Insert First");
		printf("\n2 - Insert Last");
		printf("\n3 - Insert After A Given Node");
		printf("\n4 - Insert Before A Given Node");
		printf("\n5 - Insert At A Specific Position");
		printf("\n6 - Delete First");
		printf("\n7 - Delete Last");
		printf("\n8 - Delete After A Given Node");
		printf("\n9 - Delete Before A Given Node");
		printf("\n10 - Delete At A Specifc Position");
		printf("\n11 - Delete Any Node With A Given Key\n");

		printf("\nEnter Your Option:");
		scanf("%d", &choice);

		// Switch - Case Section
		switch (choice)
		{
		case 1:
			printf("\nEnter The Element To Insert At First: ");
			scanf("%d", &ele);
			insert_first(ele);
			display();
			break;
		case 2:
			printf("\nEnter The Element To Insert At Last: ");
			scanf("%d", &ele);
			insert_last(ele);
			display();
			break;
		case 3:
			printf("\nEnter The Node: ");
			scanf("%d", &key);
			printf("\nEnter The Element To Insert After Node %d : ", key);
			scanf("%d", &ele);
			insert_after_node(key, ele);
			display();
			break;
		case 4:
			printf("\nEnter The Node: ");
			scanf("%d", &key);
			printf("\nEnter The Element To Insert Before Node %d : ", key);
			scanf("%d", &ele);
			insert_before_node(key, ele);
			display();
			break;
		case 5:
			printf("\nEnter The Position: ");
			scanf("%d", &pos);
			printf("\nEnter The Element To Insert At Position %d : ", pos);
			scanf("%d", &ele);
			insert_specific_position(pos, ele);
			display();
			break;
		case 6:
			delete_first();
			display();
			break;
		case 7:
			delete_last();
			display();
			break;
		case 8:
			printf("\nDelete After Node: ");
			scanf("%d", &key);
			delete_after_given_node(key);
			display();
			break;
		case 9:
			printf("\nDelete Before Node: ");
			scanf("%d", &key);
			delete_before_given_node(key);
			display();
			break;
		case 10:
			printf("\nDelete At Position: ");
			scanf("%d", &key);
			delete_specific_position(key);
			display();
			break;
		case 11:
			printf("\nEnter The Key To Delete: ");
			scanf("%d", &key);
			delete_any_node_with_key(key);
			display();
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}

// -  Create List
void create()
{
	struct node *new, *curr;
	char check;
	do
	{
		new = (struct node *)malloc(sizeof(struct node));
		printf("Enter Element: ");
		scanf("%d", &new->info);
		new->next = NULL;
		if (start == NULL)
		{
			start = new;
			curr = new;
		}
		else
		{
			curr->next = new;
			curr = new;
		}
		printf("Enter Choice y To Continue: ");
		scanf(" %c", &check);
	} while (check == 'y');
}

// -  Display Or Traverse Function
void display()
{
	struct node *temp;
	temp = start;
	if (temp == NULL)
	{
		printf("List Is Empty!\n");
		return;
	}
	printf("List Is: ");
	while (temp)
	{
		printf("%d ", temp->info);
		temp = temp->next;
	}
}

// 1 - Insert First
void insert_first(int ele)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Can't Be Created!\n");
		exit(0);
	}
	new->info = ele;
	new->next = start;
	start = new;
}

// 2 - Insert Last
void insert_last(int ele)
{
	struct node *new, *temp;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Can't Be Created!\n");
		exit(0);
	}
	new->info = ele;
	new->next = NULL;
	temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

// 3 - Insert After A Given Node
void insert_after_node(int key, int ele)
{
	struct node *new;
	struct node *t;
	t = start;
	while ((t != NULL) && (t->info != key))
	{
		t = t->next;
	}
	if (t == NULL)
	{
		printf("\nKey Is Not Present!\n");
		return;
	}

	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Can't Be Created!\n");
		exit(0);
	}
	new->info = ele;
	new->next = t->next;
	t->next = new;
}

// 4 - Insert Before A Given Node
void insert_before_node(int key, int ele)
{
	struct node *new;
	struct node *t, *t1;

	t = start;
	while ((t != NULL) && (t->info != key))
	{
		t1 = t;
		t = t->next;
	}
	if (t == NULL)
	{
		printf("\nKey Is Not Present!\n");
		return;
	}

	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Allocation Fails!\n");
		exit(0);
	}
	new->info = ele;
	if (t == start)
	{
		new->next = start;
		start = new;
	}
	else
	{
		new->next = t;
		t1->next = new;
	}
}

// 5 - Insert At A Specific Position
void insert_specific_position(int pos, int ele)
{
	int i;
	struct node *new, *t;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Allocation Fails!\n");
		exit(0);
	}
	new->info = ele;
	if (pos == 1)
	{
		new->next = start;
		start = new;
	}
	else
	{
		t = start;
		for (i = 1; (t != NULL) && (i < pos - 1); i++)
		{
			t = t->next;
		}
		if (t == NULL)
		{
			printf("\nInsert Not Possible!\n");
			return;
		}
		new->next = t->next;
		t->next = new;
	}
}

// 6 - Delete First
void delete_first()
{
	struct node *temp;
	temp = start;
	if (start == NULL)
	{
		printf("List IS Empty!\n");
		exit(0);
	}
	start = start->next;
	free(temp);
}

// 7 - Delete Last
void delete_last()
{
	struct node *temp, *temp1;
	temp = start;
	if (start->next == NULL)
	{
		free(temp);
		start = NULL;
	}
	else
	{
		while (temp->next)
		{
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = NULL;
		free(temp);
	}
}

// 8 - Delete After A Given Node
void delete_after_given_node(int key)
{
	struct node *temp1, *temp;
	temp1 = start;
	while (temp1 && temp1->info != key)
	{
		temp1 = temp1->next;
	}
	if (temp1 == NULL || temp1->next == NULL)
	{
		printf("Delete Not Possible!\n");
		return;
	}
	temp = temp1->next;
	temp1->next = temp->next;
	free(temp);
}

// 9 - Delete Before A Given Node
void delete_before_given_node(int key)
{
	struct node *temp, *temp1;
	temp = start;
	while (temp != NULL && (temp->next)->info != key)
	{
		temp1 = temp;
		temp = temp->next;
	}
	if (temp == start)
	{
		printf("Delete Not Possible!\n");
		return;
	}
	temp1->next = temp->next;
	free(temp);
}

// 10 - Delete A Specific Position
void delete_specific_position(int pos)
{
	struct node *temp, *temp1;
	temp1 = start;
	int i;
	if (start == NULL)
	{
		printf("Empty!\n");
		exit(0);
	}
	if (pos == 1)
	{
		temp = start;
		start = start->next;
		free(temp);
		return;
	}
	for (i = 1; temp && i < pos - 1; i++)
	{
		temp1 = temp1->next;
	}
	if (temp1 == NULL || temp1->next == NULL)
	{
		printf("Delete Not Possible!\n");
		return;
	}
	temp = temp1->next;
	temp1->next = temp->next;
	free(temp);
}

// 11 - Delete Any Node With A Given Key Value
void delete_any_node_with_key(int key)
{
	struct node *temp1, *temp;
	temp = start;
	while (temp && temp->info != key)
	{
		temp1 = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("Node Not Present!\n");
		return;
	}
	if (temp == start)
	{
		start = start->next;
	}
	else
	{
		temp1->next = temp->next;
	}
	free(temp);
}

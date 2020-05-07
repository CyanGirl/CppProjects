#include<stdio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
struct node* create()
{
	int val;
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&val);
	ptr->data=val;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
void buildtree(struct node *tree, struct node *ptr)
{
	char h,ch;
	struct node *str;
	str = tree;
	printf("Do you want to insert as left or as right child(L/R)?");
	scanf(" %c",&h);
	if(h =='L')
	{
		if(str->left==NULL)
		{
			str->left = ptr;
		}
		else
		{
			str=str->left;
			buildtree(str, ptr);
		}
	}
	else if(h =='R')
	{
		if(str->right==NULL)
		{
			str->right = ptr;
		}
		else
		{
			str=str->right;
			buildtree(str, ptr);
		}
	}
	return;
}
void traversal(struct node *tree)
{
	if( tree ==NULL)
	{
		return;
	}
	else
	{
		traversal(tree->left);
		traversal(tree->right);
		printf("%d   ",tree->data);
	}
}
void main()
{
	int val;
	char ch;
	struct node *tree, *ptr;
	tree = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data of root");
	scanf("%d",&val);
	tree->data=val;
	tree->left = NULL;
	tree->right = NULL;
	while(1)
	{
		printf("Do you want to continue(Y/N)?");
		scanf(" %c",&ch);
		if(ch=='Y')
		{
			ptr = create();
			buildtree(tree, ptr);
		}
		else if(ch=='N')
		{
			break;
		}
	}
	traversal(tree);
}
#include <stdio.h>

#if 0

typedef struct _node
{
	char *name;
	struct _node *left;
	struct _node *right;
} Node;

Node root, n1, n2, n3, n4, n5, n6;

void Inorder_Traverse(Node *p)
{
	if (p->left) Inorder_Traverse(p->left);
	printf(" %s", p->name);
	if (p->right) Inorder_Traverse(p->right);
}

void Preorder_Traverse(Node *p)
{
	printf(" %s", p->name);
	if (p->left) Preorder_Traverse(p->left);
	if (p->right) Preorder_Traverse(p->right);
}

void Postorder_Traverse(Node *p)
{
	if (p->left) Postorder_Traverse(p->left);
	if (p->right) Postorder_Traverse(p->right);
	printf(" %s", p->name);
}

void Init_Tree(void)
{
	root.left = &n1;
	root.right = &n2;
	root.name = "ROOT";

	n1.left = &n3;
	n1.right = &n4;
	n1.name = "N1";

	n2.left = &n5;
	n2.right = &n6;
	n2.name = "N2";

	n3.left = n3.right = n4.left = n4.right = n5.left = n5.right = n6.left = n6.right = NULL;
	n3.name = "N3";
	n4.name = "N4";
	n5.name = "N5";
	n6.name = "N6";
}

int main(void)
{
	Init_Tree();

	printf("Inorder Traverse :");
	Inorder_Traverse(&root);
	printf("\n");

	printf("Preorder Traverse :");
	Preorder_Traverse(&root);
	printf("\n");

	printf("Postorder Traverse :");
	Postorder_Traverse(&root);
	printf("\n");
	return 0;
}



#endif

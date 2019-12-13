#include<stdio.h>
#include<conio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

int height(node *tree)
{
    if(tree==NULL)
        return 0;
    else
        return(tree->height);
}

int max(int a,int b)
{
    return((a>b)?a:b);
}

node* newnode(int key)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=key;
    temp->left=temp->right=NULL;
    temp->height=1;
    return temp;
}

node* RR(node *A)
{
    node *B=A->left;
    node *D=B->right;

    B->right=A;
    A->left=D;
    A->height=max(height(A->left),height(A->right))+1;
    B->height=max(height(B->left),height(B->right))+1;
    return B;
}

node* LL(node *A)
{
    node *B=A->right;
    node *D=B->left;

    B->left=A;
    A->right=D;
    A->height=max(height(A->left),height(A->right))+1;
    B->height=max(height(B->left),height(B->right))+1;
    return B;
}

int getbalance(node *tree)
{
    if(tree==NULL)
        return 0;
    else
        return(height(tree->left)-height(tree->right));
}

node* insert(node *node,int key)
{
    if(node==NULL)
    {
        return (newnode(key));
    }
    else
    {
        if(key<node->data)
            {
                node->left=insert(node->left,key);
            }
        else if(key>node->data)
            {
                node->right=insert(node->right,key);
            }
    }

    node->height=1+ max(height(node->left),height(node->right));
    int BF=getbalance(node);

    if(BF>1 && key<node->left->data)
    {
        return(RR(node));
    }

    if(BF>1 && key>node->left->data)
    {
        node->left=LL(node->left);
        return(RR(node));
    }

    if(BF<-1 && key>node->right->data)
    {
        return(LL(node));
    }

    if(BF<-1 && key<node->right->data)
    {
        node->right=RR(node->right);
        return(RR(node));
    }
    return node;
}

node* create()
{
    node *node=NULL;
    return node;
}

void inorder(node *node)
{
    if(node==NULL)
        return;
    else
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

void preorder(node *node)
{
    if(node==NULL)
        return;
    else
    {
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

node* maxx(node *root)
{
    if(root==NULL)
        return NULL;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

node* del(node *root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(key<root->data)
    {
        root->left=del(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=del(root->right,key);
    }
    else
        {
            if(root->left==NULL && root->right==NULL)
                root=NULL;
            else if(root->right==NULL)
                root=root->left;
            else if(root->left==NULL)
                root=root->right;
            else
            {
                node *temp = maxx(root->left);
                root->data=temp->data;
                root->left=del(root->left,temp->data);
            }
        }

    if(root==NULL)
        return root;

    root->height=1+ max(height(root->left),height(root->right));
    int BF=getbalance(root);

    if(BF>1 && getbalance(root->left) >= 0)
    {
        return(RR(root));
    }

    if(BF>1 && getbalance(root->left) < 0)
    {
        root->left=LL(root->left);
        return(RR(root));
    }

    if(BF<-1 && getbalance(root->right) < 0)
    {
        return(LL(root));
    }

    if(BF<-1 && getbalance(root->right) >= 0)
    {
        root->right=RR(root->right);
        return(RR(root));
    }
        return root;
}

main()
{
    int c,key;
    node *node;
    do
    {
        printf("\n Enter your choice");
        printf("\n 1 Create");
        printf("\n 2 Insert");
        printf("\n 3 Inorder");
        printf("\n 4 Preorder");
        printf("\n 5 Delete");
        printf("\n 6 Exit   ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: node= create();
                    break;
            case 2: printf("\n Enter The Data  ");
                    scanf("%d",&key);
                    node=insert(node,key);
                    break;
            case 3: inorder(node);
                    break;
            case 4: preorder(node);
                    break;
            case 5: printf("\n Enter The Data  ");
                    scanf("%d",&key);
                    node=del(node,key);
                    break;

        }
    }while(c!=6);
    
    


	printf("\nLevel Order Traversal :: \n");
	struct node *(queue[20]);
	int front, rear;
	front = rear = -1;

	struct node *dummy = NULL;
	dummy = (struct node *)malloc(sizeof(struct node));
	dummy->data = -1000;
	dummy->left = NULL;
	dummy->right = NULL;

	queue[++rear] = node;
	queue[++rear] = dummy;

	struct node *temp = NULL;

	while((front+1) != rear)
	{
		temp = queue[++front];
		if(temp->data != -1000)
		{
			printf("%d, ", temp->data);
			
			if(temp->left)
				queue[++rear] = temp->left;

			if(temp->right)
				queue[++rear] = temp->right;
		}
		else
		{
			queue[++rear] = dummy;
			printf("\n");
		}
	}



}

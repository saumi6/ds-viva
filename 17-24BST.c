//Just keep the methods you are asked to do in the question
//Remove the method definitions and the method calls in the main function
//Make sure to make changes in the main function accordingly
//If possible, re-write the menu driven code in main
#include <stdio.h>
#include <stdlib.h>

// TNode structure formed
typedef struct node
{
    int data;
    struct node *left, *right;
} Tnode;

// Tree struct formed
typedef struct
{
    Tnode *root;
} Tree;

// insert method
void insert(Tree *t, int x)
{
    // node creation and memory allocation
    Tnode *p;
    p = (Tnode *)malloc(sizeof(Tnode));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    /// if the inserting node is the 1st node
    if (t->root == NULL)
        t->root = p;

    // if it is not the first node

    else
    {
        // taking node 'q' for traversal and node 'prev' to keep track of parent of 'q'
        Tnode *q = t->root, *prev = NULL;
        while (q != NULL)
        {
            prev = q;
            if (p->data < q->data) // if data is smaller than current 'q' than increment 'q'
                q = q->left;
            else
                q = q->right; // if data is bigger
        }
        // here prev is the parent of new node to be inserted
        if (p->data < prev->data)
            prev->left = p; // if data is small then in left
        else
            prev->right = p;
    }
}

// delete method
Tnode *delete(Tnode *root, int x)
{
    Tnode *prev = NULL, *p, *q, *r;
    p = root; // using p for traversal

    // to find the node with required data
    while (p != NULL) // while a node exists
    {
        if (p->data == x) // if the current node contains the node to be deleted
            break;
        else
        {
            prev = p;        // keeping note of the parent node
            if (x < p->data) // the current node data is greater

                p = p->left;
            else
                p = p->right;
        }
    }

    // go to left subtree

    // node with required data found i.e 'p' and 'prev' is the parent
    if (p == NULL)
        printf("Data not found \n");
    else
    {
        // leaf node or node with only one subtree
        // case 1 & case 2
        if (p->left == NULL || p->right == NULL)
            q = p;
        else // case 3- has both subtrees
        {
            prev = p; // updating prev for case 3
            q = p->right;
            while (q->left != NULL)
            {
                prev = q;
                q = q->left;
            }
            p->data = q->data;
        }

        // deciding r
        if (q->left == NULL)
            r = q->right; // if no left subtree exists then right subtree will take part of deleted node
        // also works for case 1 else
        r = q->left;

        // linking 'prev' with 'r'
        if (prev == NULL)
            root = r;

        else if (prev->left == q)
            prev->left = r;
        else
            prev->right = r;

        // deleting 'q'
        printf("Deleted node: %d \n ", q->data);
        free(q);
        return root;
    }
}

// inorder display
void inorder(Tnode *r) // LVR
{
    // if there is no node
    if (r == NULL)
        return;
    else
    {
        inorder(r->left);        // L
        printf(" %d ", r->data); // V
        inorder(r->right);       // R
    }
}

// postorder display
void postorder(Tnode *r) // LRV
{
    // if there is no node
    if (r == NULL)
        return;
    else
    {
        postorder(r->left);  // L
        postorder(r->right); // R

        printf(" %d ", r->data); // V
    }
}

// preorder display
void preorder(Tnode *r) // VLR
{
    // if there is no node
    if (r == NULL)
        return;
    else
    {
        printf(" %d ", r->data); // V
        preorder(r->left);       // L
        preorder(r->right);      // R
    }
}

// find min
int FindMin(Tnode *r)
{
    // left most node holds the smallest data
    // thus traversing to the smallest node
    while (r->left != NULL)
    {
        r = r->left;
    }
    return r->data;
}

// find max
int FindMax(Tnode *r)
{
    // right most node holds biggest data
    // traversing to right
    while (r->right != NULL)
    {
        r = r->right;
    }
    return r->data;
}

// Count number of node
int CountNodes(Tnode *r)
{
    // indicates no node
    if (r == NULL)
        return 0;
    else
        return (1 + CountNodes(r->left) + CountNodes(r->right));
}

// Count number of leaves
int CountLeaf(Tnode *r)
{
    if (r == NULL)
        return 0;
    // leaf node condition
    else if ((r->left == NULL) && (r->right == NULL))
        return 1;
    else
        return (CountLeaf(r->left) + CountLeaf(r->right));
}

// height
int height(Tnode *r)
{
    // no node
    if (r == NULL)
        return -1;
    // only one node
    else if ((r->left == NULL) && (r->right == NULL))
        return 0;
    else
    {

        int lh = height(r->left);
        int rh = height(r->right);

        if (lh > rh)
            return (lh + 1);

        else
            return (rh + 1);
    }
}

// searching without recursion
Tnode *search(Tnode *r, int x)
{
    while (r != NULL)
    {
        if (r->data == x)
            return r;
        else if (r->data > x)
            r = r->left;
        else
            r = r->right;
    }
    return NULL;
}

// searching with recursion
Tnode *searchRec(Tnode *r, int x)
{
    if (r == NULL)
        return NULL;
    else if (r->data == x)
        return r;
    else if (r->data > x)
        return searchRec(r->left, x);
    else
        return searchRec(r->right, x);
}

// mirror method
void mirror(Tnode *node)
{
    if (node == NULL)
        return;
    else
    {
        Tnode *temp;

        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);

        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
// main method
int main()
{
    Tree t;
    t.root = NULL;
    int option = 0, ele;
    Tnode *s, *sr, *ro;
    do
    {
        printf("1.Insertion 2.Deletion 3.Inorder 4.Postorder 5.Preorder 6.Maximum 7.Minimum 8.Search \n9.Search(recursive) 10.Total_nodes 11.Leaf_nodes 12.Height 13.Mirror 14.Exit\n Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &ele);
            insert(&t, ele);

            break;

        case 2:
            printf("Enter the data to be deleted:");
            scanf("%d", &ele);
            ro = delete (t.root, ele);
            break;

        case 3:
            inorder(t.root);
            printf("\n");
            break;

        case 4:
            postorder(t.root);
            printf("\n");
            break;

        case 5:
            preorder(t.root);
            printf("\n");
            break;

        case 6:
            printf("Maximum is: %d \n", FindMax(t.root));
            break;

        case 7:
            printf("Minimum is: %d \n", FindMin(t.root));
            break;

        case 8:
            printf("Enter data to be searched: ");
            scanf("%d",&ele);
            s = search(t.root, ele);
            if(s==NULL) printf("Element isnt in the list");
            else printf("Element is in the list");
            break;

        case 9:
            printf("Enter data to be searched: ");
            scanf("%d",&ele);
            sr = searchRec(t.root, ele);
            if(sr==NULL) printf("Element isnt in the list");
            else printf("Element is in the list");
            break;

        case 10:
            printf("Nodes = %d \n", CountNodes(t.root));
            break;

        case 11:
            printf("Leaves = %d \n", CountLeaf(t.root));
            break;

        case 12:
            printf("Height = %d \n", height(t.root));
            break;

        case 13:
            mirror(t.root);
            break;

        case 14:
            break;

        default:
            printf("Enter valid option \n");
            break;
        }
    } while (option != 14);
    return 0;
}

// Given a binary tree which has T nodes, you need to find the diameter of that binary tree. The diameter of a tree is the number of nodes on 
// the longest path between two leaves in the tree.

/*

Input:
First line contains two integers, T and X, number of nodes in the tree and value of the root.
Next 2×(T−1) lines contain details of nodes. Each detail of node contains two lines. 
First lines contains a string and second line contains an integer, which denotes the path of the node and the value of the node respectively.

String consists of only L or R.L denotes left child and R denotes right child. ( Look at the sample explanation for more details ) 
*/

/*
*   @coder : devsks (Santosh Kumar Shaw)
*   @college : Academy Of Technology (WB)
*   @quote : "Code Like Thers's No Tommorow!"
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node{
    int val, lh, rh;
    struct node *left, *right;
}node;
// Allocates new nodes.
node * getNode(int val){
    node *ret = (node*)calloc(1, sizeof(node));
    ret->val = val;
    return ret;
} 
int max; // our Diameter.
//Assign maximum Depth to each node.
int query(node *ptr){
    if(ptr){
        ptr->lh = query(ptr->left);
        ptr->rh = query(ptr->right);
        if (ptr->lh + ptr->rh + 1  > max)
            max = ptr->lh + ptr->rh + 1;
        return ( ptr->lh > ptr->rh ? ptr->lh : ptr->rh) + 1;
    }
    else
        return 0;
}
int main()
{
    max = INT_MIN;
    node *root = NULL,*ptr;
    int n, x, i ;
    scanf("%i %i",&n,&x);
    root = getNode(x);
    char str[12345];
    while(--n){
        scanf(" %s",str);
        i = 0;
        ptr = root;
        while(str[i] && ptr ){
            if(str[i] == 'L'){
                if(ptr->left == NULL)
                    ptr->left = getNode(0);
                ptr = ptr->left;

            }
            else{
                if(ptr->right == NULL)
                    ptr->right = getNode(0);
                ptr = ptr->right;

            }
            i++;
        }
        scanf("%i", &x);
        ptr->val = x;

    }
    query(root);
    printf("%i", max);
    return 0;
}
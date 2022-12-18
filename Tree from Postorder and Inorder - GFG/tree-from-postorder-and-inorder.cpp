//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
   Node* solve(int in[],int post[], int n,int& idx,int left,int right,map<int,int>&mapper){
        if(left>right || idx<0){
            return NULL;
        }
        int element = post[idx];
        idx--;
        int pivot = mapper[element];
        Node* newnode=new Node(element);
        newnode->right=solve(in,post,n,idx,pivot+1,right,mapper);
        newnode->left=solve(in,post,n,idx,left,pivot-1,mapper);
        return newnode;
    }
    Node* buildTree(int in[],int post[], int n)
    {
         int idx=n-1;
         map<int,int>mapper;
         for(int i =0;i<n;i++){
            mapper[in[i]]=i;
         }
         return solve(in,post,n,idx,0,n-1,mapper);
    }

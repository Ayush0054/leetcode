//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:Node* solve(int in[],int pre[], int n,int& idx,int left,int right,map<int,int>&mapper){
        if(left>right){
            return NULL;
        }
        int element = pre[idx];
        idx++;
        int pivot = mapper[element];
        Node* newnode=new Node(element);
        newnode->left=solve(in,pre,n,idx,left,pivot-1,mapper);
        newnode->right=solve(in,pre,n,idx,pivot+1,right,mapper);
        return newnode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
         int idx=0;
         map<int,int>mapper;
         for(int i =0;i<n;i++){
            mapper[in[i]]=i;
         }
         return solve(in,pre,n,idx,0,n-1,mapper);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
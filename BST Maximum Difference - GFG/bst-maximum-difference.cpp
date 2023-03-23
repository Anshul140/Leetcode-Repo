//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int ans = INT_MIN;
    int f;
    int tar;
    int s1 = 0;
    int s2 = 0;
    
    void dfs(Node* root) {
        if(root == NULL)
           return;
           
        if(root->data == tar) {
            f = 1;
            if(root->right == NULL and root->left == NULL) {
                if(f == 1) {
                    ans = max(ans, s1-s2);
                }
                f = 0;
                return;
            }
            
            dfs(root->left);
            dfs(root->right);
            f = 0;
        }      
        
        if(root->right == NULL and root->left == NULL) {
            // cout<<"leaf: "<<root->data<<endl;
            // cout<<"s1: "<<s1<<" s2: "<<s2<<endl;
            // cout<<"found ? "<<f<<endl<<endl;
            if(f == 1) {
                s2 += root->data;
                // cout<<"leaf: "<<root->data<<endl;
                // cout<<"s1: "<<s1<<" s2: "<<s2<<endl;
                ans = max(ans, s1-s2);
                s2 -= root->data;
                return;
            }
            return;
        }
        
        if(f == 0) {
            s1 += root->data;
            dfs(root->left);
            dfs(root->right);
            s1 -= root->data;
        } else {
            s2 += root->data;
            dfs(root->left);
            dfs(root->right);
            s2 -= root->data;
        }
    }
    
    int maxDifferenceBST(Node *root,int target){
        // Code here
        tar = target;
        f = 0;
        s1 = s2 = 0;
        dfs(root);
        return ans == INT_MIN? -1: ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
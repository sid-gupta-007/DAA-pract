#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right); // Added missing semicolon
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void levelOrder(Node *root)
{
    if (!root)
        return;

    Node *q[100]; // Changed 'a' to 'q' to match the rest of your logic
    int f = 0, r = 0;
    q[r++] = root;

    while (f < r)
    {
        Node *temp = q[f++];
        cout << temp->data << " ";

        if (temp->left)
            q[r++] = temp->left;
        if (temp->right)
            q[r++] = temp->right;
    }
}

int main()
{
    Node *root = NULL;
    int n, val, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the node value: ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "\n1. Preorder\n2. Inorder\n3. Postorder\n4. Level Order\nEnter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Preorder: ";
        preorder(root);
        break;
    case 2:
        cout << "Inorder: ";
        inorder(root);
        break;
    case 3:
        cout << "Postorder: ";
        postorder(root);
        break;
    case 4:
        cout << "Level Order: ";
        levelOrder(root);
        break;
    default:
        cout << "Invalid Choice";
    }
    return 0;
}

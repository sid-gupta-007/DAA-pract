import java.util.*;

class TreeTraversal {

    static class Node {
        int data;
        Node left, right;
        Node(int val) {
            data = val;
            left = right = null;
        }
    }

    static Node insert(Node root, int val) {
        if (root == null)
            return new Node(val);
        if (val < root.data)
            root.left = insert(root.left, val);
        else
            root.right = insert(root.right, val);
        return root;
    }

    static void preorder(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }

    static void postorder(Node root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data + " ");
        }
    }

    static void levelOrder(Node root) {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            Node temp = q.poll();
            System.out.print(temp.data + " ");

            if (temp.left != null) q.add(temp.left);
            if (temp.right != null) q.add(temp.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = null;

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter node value: ");
            int val = sc.nextInt();
            root = insert(root, val);
        }

        System.out.println("\n1. Preorder\n2. Inorder\n3. Postorder\n4. Level Order");
        System.out.print("Enter choice: ");
        int choice = sc.nextInt();

        switch (choice) {
            case 1:
                System.out.print("Preorder: ");
                preorder(root);
                break;
            case 2:
                System.out.print("Inorder: ");
                inorder(root);
                break;
            case 3:
                System.out.print("Postorder: ");
                postorder(root);
                break;
            case 4:
                System.out.print("Level Order: ");
                levelOrder(root);
                break;
            default:
                System.out.print("Invalid Choice");
        }
    }
}

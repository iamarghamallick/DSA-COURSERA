public class test {
    static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // build a tree from its Pre-order Traversal
    static class BinaryTree {
        static int index = -1;

        public Node buildTree(int nodes[]) {
            index++;
            if (nodes[index] == -1) {
                return null;
            }
            Node newNode = new Node(nodes[index]);
            newNode.left = buildTree(nodes);
            newNode.right = buildTree(nodes);
            return newNode;
        }
    }

    public static int heightOfTree(Node root) {
        if (root == null) {
            return 0;
        }
        int leftH = heightOfTree(root.left);
        int rightH = heightOfTree(root.right);
        return Math.max(leftH, rightH) + 1;
    }

    public static void main(String[] args) {
        int nodes[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
        BinaryTree tree = new BinaryTree();
        Node root = tree.buildTree(nodes);

        int heightRes = heightOfTree(root);
        System.out.println(heightRes);
    }
}
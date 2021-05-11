package DocumentWordBinaryTree;

import java.util.LinkedList;

public class Node {

    private String key;
    private Long value;
    private Node parent;
    private Node left;
    private Node right;

    public Node(String key, Long value) {
        this.key = key;
        this.value = value;
        this.parent = null;
        this.left = null;
        this.right = null;
    }
    public Node(String key, Long value, Node left, Node right) {
        this.key = key;
        this.value = value;
        this.left = left;
        this.right = right;
        this.parent = null;
    }

    public String getKey() {
        return key;
    }

    public Long getValue() {
        return value;
    }

    public Node getParent() {
        return parent;
    }

    public Node getLeft() {
        return left;
    }

    public Node getRight() {
        return right;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public void setValue(Long value) {
        this.value = value;
    }

    public void setParent(Node parent) {
        this.parent = parent;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public void setRight(Node right) {
        this.right = right;
    }
    public LinkedList<Node> getChilds() {
        LinkedList<Node> nodeList = new LinkedList<>();
        if (this.left != null) {
            nodeList.add(this.left);
        }
        if (this.right != null) {
            nodeList.add(this.right);
        }
        return nodeList;
    }
    public void print() {
        print("",this, false);
    }

    private void print(String prefix, Node node, boolean isLeft) {
        if (node != null) {
            System.out.println (prefix + (isLeft ? "|-- " : "\\-- ") + node.getKey() + "=" + node.getValue());  
            print(prefix + (isLeft ? "|   " : "    "), node.right, true);
            print(prefix + (isLeft ? "|   " : "    "), node.left, false);
        }
    }
 

}

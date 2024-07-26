import random


class TreeNode:
    def __init__(self, key):
        self.key = key
        self.children = []

    def __str__(self):
        return str(self.key)

    def add_child(self, child):
        self.children.append(child)


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key, parent_key=None):
        if not self.root:
            self.root = TreeNode(key)
        else:
            parent_node = self._search_node(self.root, parent_key)
            if parent_node:
                parent_node.add_child(TreeNode(key))
            else:
                raise ValueError("Parent key not found.")

    def _serach_node(self, node, key):
        if node.key == key:
            return node
        for child in node.children:
            result = self._search_node(child, key)
            if result:
                return result
        return None


class BinaryTreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.size = 1

    def __str__(self):
        return str(self.key)

    def get_Ith_node(self, i):
        left_size = self.left.size if self.left != None else 0
        if i < left_size:
            return self.left.get_Ith_node(i)
        elif i == left_size:
            return self
        else:
            return self.right.get_Ith_node(i - (left_size + 1))


class BinaryTree:
    def __init__(self):
        self.root = None

    def size(self):
        return self.root.size if self.root != None else 0

    def insert(self, key):
        if not self.root:
            self.root = BinaryTreeNode(key)
        else:
            self._insert_node(self.root, key)

    def _insert_node(self, node, key):
        node.size += 1
        if key < node.key:
            if node.left is None:
                node.left = BinaryTreeNode(key)
            else:
                self._insert_node(node.left, key)
        else:
            if node.right is None:
                node.right = BinaryTreeNode(key)
            else:
                self._insert_node(node.right, key)

    def inorder_traversal(self):
        traversal = []
        self._inorder_traversal_recursive(self.root, traversal)
        return traversal

    def _inorder_traversal_recursive(self, node, traversal):
        if node:
            self._inorder_traversal_recursive(node.left, traversal)
            traversal.append(str(node))
            self._inorder_traversal_recursive(node.right, traversal)

    def get_random_node(self):
        if self.root == None:
            return None
        rand_num = random.randint(0, self.size() - 1)
        return self.root.get_Ith_node(rand_num)

    def print_tree(self):
        self._print_tree_recursive(self.root, 0)

    def _print_tree_recursive(self, root, level=0, prefix=""):
        if root is not None:
            print(" " * (level * 4) + prefix + str(root.key))
            if root.left is not None or root.right is not None:
                self._print_tree_recursive(root.left, level + 1, "L:")
                self._print_tree_recursive(root.right, level + 1, "R:")

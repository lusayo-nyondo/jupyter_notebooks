from collections import deque
from typing import List, Callable, Deque


class TreeNode:
    def __init__(
        self,
        value=None,
        left: type['TreeNode']=None,
        right: type['TreeNode']=None,
    ):
        self.left = left
        self.right = right
        self.value = value


class BinaryTree:
    def __init__(
            self,
            root: TreeNode=None,
        ):
        self.root = root
    
    def load_from_array(
            self,
            array: List,
        ):
        if array is None:
            self.root = None
        
        node_queue: Deque[TreeNode] = deque()

        self.root = TreeNode(array[0])

        node_queue.append(self.root)

        i = 1
        while node_queue and i < len(array):
            current_node = node_queue.popleft()

            if i < len(array) and array[i] is not None:
                current_node.left = TreeNode(array[i])
                node_queue.append(current_node.left)
            
            i += 1

            if i < len(array) and array[i] is not None:
                current_node.right = TreeNode(array[i])
                node_queue.append(current_node.right)
            
            i += 1

    def in_order_traversal(
            self,
            func: Callable=print,
            node: TreeNode=None,
        ):
        if self.root is None:
            return

        if node is None:
            node = self.root

        if node.left:
            self.in_order_traversal(
                func=func,
                node=node.left,
            )
        
        func(node.value)
        
        if node.right:
            self.in_order_traversal(
                func=func,
                node=node.right,
            )

    def post_order_traversal(
            self,
            func: Callable=print,
            node: TreeNode=None,
        ):
        if self.root is None:
            return

        if node is None:
            node = self.root
        
        if node.left:
            self.post_order_traversal(
                func=func,
                node=node.left,
            )
        
        if node.right:
            self.post_order_traversal(
                func=func,
                node=node.right,
            )

        func(node.value)


    def pre_order_traversal(
            self,
            func: Callable,
            node: TreeNode=None,
        ):
        if self.root is None:
            return

        if node is None:
            node = self.root

        func(node.value)

        if node.left:
            self.pre_order_traversal(
                func=func,
                node=node.left,
            )

        if node.right:
            self.pre_order_traversal(
                func=func,
                node=node.right,
            )


class BinarySearchTree(BinaryTree):
    def __init__(
            self,
            root: TreeNode=None,
        ):
        self.root = root

    def insert(
            self,
            value,
        ):
        pass

    def search(
            self,
            value,
        ):
        pass

    def pop(self):
        pass


class AVLTree(BinaryTree):
    def __init__(
            self, root: TreeNode=None
        ):
        self.root = root

    def insert(
            self,
            value,
        ):
        pass

    def search(
            self,
            value,
        ):
        pass

    def pop(self):
        pass


class RedBlackTree(BinaryTree):
    def __init__(
            self, root: TreeNode=None
        ):
        self.root = root
    
    def insert(
            self,
            value,
        ):
        pass

    def search(
            self,
            value,
        ):
        pass


class WeightedGraph:
    def add_node(self, node):
        pass

    def add_edge(
            self,
            node_1,
            node_2,
        ):
        pass

    def pop_node(self):
        pass

    def remove_edge(
            self,
            node_1,
            node_2,
        ):
        pass

class UnweightedGraph:
    def add_node(self, node):
        pass

    def add_edge(
            self,
            node_1,
            node_2,
        ):
        pass

    def pop_node(self):
        pass
    
    def remove_edge(
            self,
            node_1,
            node_2,
        ):
        pass

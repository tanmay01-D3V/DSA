class BTreeNode:
    def __init__(self, t, leaf=False):
        self.t = t  # Minimum degree
        self.leaf = leaf
        self.keys = []
        self.children = []


class BTree:
    def __init__(self, t):
        self.root = BTreeNode(t, leaf=True)
        self.t = t

    def search(self, k, node=None):
        if node is None:
            node = self.root

        i = 0
        while i < len(node.keys) and k > node.keys[i]:
            i += 1

        if i < len(node.keys) and k == node.keys[i]:
            return (node, i)

        if node.leaf:
            return None

        return self.search(k, node.children[i])

    def insert(self, k):
        root = self.root
        # If root is full (2t - 1 keys), split it and grow the tree upward
        if len(root.keys) == (2 * self.t) - 1:
            new_root = BTreeNode(self.t, leaf=False)
            self.root = new_root
            new_root.children.append(root)
            self._split_child(new_root, 0)
            self._insert_non_full(new_root, k)
        else:
            self._insert_non_full(root, k)

    def _insert_non_full(self, node, k):
        i = len(node.keys) - 1

        if node.leaf:
            node.keys.append(None)
            while i >= 0 and k < node.keys[i]:
                node.keys[i + 1] = node.keys[i]
                i -= 1
            node.keys[i + 1] = k
        else:
            while i >= 0 and k < node.keys[i]:
                i -= 1
            i += 1

            # Preemptively split full child before descending
            if len(node.children[i].keys) == (2 * self.t) - 1:
                self._split_child(node, i)
                if k > node.keys[i]:
                    i += 1

            self._insert_non_full(node.children[i], k)

    def _split_child(self, parent, i):
        t = self.t
        full_child = parent.children[i]
        new_child = BTreeNode(t, leaf=full_child.leaf)

        # Promote the median key (index t - 1) to parent
        parent.keys.insert(i, full_child.keys[t - 1])
        parent.children.insert(i + 1, new_child)

        # Split keys between the two children
        new_child.keys = full_child.keys[t : (2 * t) - 1]
        full_child.keys = full_child.keys[0 : t - 1]

        # Split child pointers if not a leaf
        if not full_child.leaf:
            new_child.children = full_child.children[t : 2 * t]
            full_child.children = full_child.children[0:t]

    def display(self, node=None, level=0):
        if node is None:
            node = self.root
        print(f"Level {level}: {node.keys}")
        for child in node.children:
            self.display(child, level + 1)


# --- Example Usage ---
if __name__ == "__main__":
    btree = BTree(t=3)  # Minimum degree 3 (max 5 keys per node)
    values = [10, 20, 5, 6, 12, 30, 7, 17, 3, 25, 40, 50]

    for val in values:
        btree.insert(val)

    print("B-Tree Structure:")
    btree.display()

    print("\nSearch Results:")
    print("Find 17:", "Found" if btree.search(17) else "Not Found")
    print("Find 99:", "Found" if btree.search(99) else "Not Found")

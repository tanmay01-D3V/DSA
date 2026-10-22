"""Singly linked list for student records (ID, name, next reference)."""


class Node:
    def __init__(self, student_id, name):
        self.student_id = student_id
        self.name = name
        self.next = None


class StudentList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    # ---------- Insertion ----------
    def insert_at_beginning(self, student_id, name):
        node = Node(student_id, name)
        node.next = self.head          # new node points to old head
        self.head = node               # head moves to new node

    def insert_at_end(self, student_id, name):
        node = Node(student_id, name)
        if self.head is None:          # empty list: new node becomes head
            self.head = node
            return
        current = self.head
        while current.next is not None:
            current = current.next
        current.next = node

    def insert_at_position(self, position, student_id, name):
        """Position is 0-based: 0 = beginning, count() = end."""
        if position < 0 or position > self.count():
            print(f"Invalid position {position}. Valid range: 0 to {self.count()}.")
            return False
        if position == 0:
            self.insert_at_beginning(student_id, name)
            return True
        node = Node(student_id, name)
        current = self.head
        for _ in range(position - 1):  # stop at node just before the position
            current = current.next
        node.next = current.next
        current.next = node
        return True

    # ---------- Deletion ----------
    def delete_by_id(self, student_id):
        if self.head is None:
            print("List is empty. Nothing to delete.")
            return False
        if self.head.student_id == student_id:   # special case: deleting head
            self.head = self.head.next
            return True
        prev, current = self.head, self.head.next
        while current is not None:
            if current.student_id == student_id:
                prev.next = current.next         # bypass the node
                return True
            prev, current = current, current.next
        print(f"Student with ID {student_id} not found.")
        return False

    # ---------- Search ----------
    def search_by_id(self, student_id):
        if self.head is None:
            print("List is empty. Nothing to search.")
            return None
        current = self.head
        while current is not None:
            if current.student_id == student_id:
                print(f"Found -> ID: {current.student_id}, Name: {current.name}")
                return current
            current = current.next
        print(f"Student with ID {student_id} not found.")
        return None

    # ---------- Display / Count ----------
    def display(self):
        if self.head is None:
            print("List is empty: NULL")
            return
        parts = []
        current = self.head
        while current is not None:
            parts.append(f"{current.student_id} ({current.name})")
            current = current.next
        print(" -> ".join(parts) + " -> NULL")

    def count(self):
        total, current = 0, self.head
        while current is not None:
            total += 1
            current = current.next
        return total

    # ---------- Reverse ----------
    def reverse(self):
        prev, current = None, self.head
        while current is not None:
            next_node = current.next   # save the rest of the list
            current.next = prev        # flip the link
            prev = current             # advance prev
            current = next_node        # advance current
        self.head = prev


if __name__ == "__main__":
    students = StudentList()

    print("--- Empty list handling ---")
    students.display()
    students.search_by_id(101)
    students.delete_by_id(101)

    print("\n--- Build initial list ---")
    students.insert_at_end(101, "Asha")
    students.insert_at_end(102, "Ravi")
    students.insert_at_end(103, "Meera")
    students.display()

    print("\n--- Insert 100 at beginning ---")
    students.insert_at_beginning(100, "Karan")
    students.display()

    print("\n--- Insert 104 at end ---")
    students.insert_at_end(104, "Neha")
    students.display()

    print("\n--- Insert 105 at position 2 ---")
    students.insert_at_position(2, 105, "Vikram")
    students.display()
    students.insert_at_position(99, 999, "Invalid")

    print("\n--- Delete 102 ---")
    students.delete_by_id(102)
    students.delete_by_id(105)
    students.display()

    print("\n--- Search ---")
    students.search_by_id(103)
    students.search_by_id(555)

    print("\n--- Count ---")
    print("Total students:", students.count())

    print("\n--- Reverse ---")
    students.reverse()
    students.display()
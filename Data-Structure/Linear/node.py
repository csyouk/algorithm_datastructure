class LinkedList(object):
    def __init__(self, head = None):
        self.head = head

    def insert(self, data):
        new = Node(data)
        # for node in self.head:
        #     pass
        new.set_next(self.head)
        self.head = new

    def size(self):
        current = self.head
        cnt = 0
        while current:
            cnt += 1
            current = current.get_next()
        return cnt

    def search(self, data):
        current = self.head
        found = False
        while current and found is False:
            if current.get_data() == data:
                found = not found
            else:
                current = current.get_next()
        if current is None:
            raise ValueError("Data not in list!!")
        return current

    def delete(self, data):
        current = self.head
        prev = None
        found = False
        while current and found is False:
            if current.get_data() == data:
                found = not found
            else:
                prev = current
                current = current.get_next()
        if current is None:
            raise ValueError("Data not in list!!")
        if prev is None:
            self.head = current.get_next()
        else:
            prev.set_next(current.get_next())

    def print_all_node(self):
        current = self.head
        cnt = 0
        while current:
            cnt += 1
            if current is not None: print(current.get_data())
            current = current.get_next()

class Node(object):
    def __init__(self, data=None, next_node = None):
        self.data = data
        self.next_node = next_node

    def __str__(self):
        return "Node ID is " + str(self.data) + ", and it's located in " + str(hex(id(self)))

    def get_data(self):
        return self.data

    def set_next(self, new_next):
        self.next_node = new_next

    def get_next(self):
        return self.next_node


def main():
    lln = LinkedList()

    for i in range(1,11):
        lln.insert(Node(i))

    print("Linked list node has %d element." % (lln.size()))
    lln.print_all_node()

if __name__ == '__main__':
    main()

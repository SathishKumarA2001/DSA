class Node:

    def __init__(self,data,next_node=None):
        self.data = data
        self.next = next_node
    
    def __repr__(self):
        return "<node data: %s>" % self.data

class LinkedList:
    def __init__(self):
        self.head = None
        self.__count = 0
    
    def isEmpty(self):
        return self.head is None 

    def __len__(self):
        return self.__count

    def add(self,data):
        new_head = Node(data,next_node=self.head)
        self.head = new_head
        self.__count+=1
    
    def search(self,key):
        current = self.head
        while current:
            if(current.data == key):
                return current
            else:
                current = current.next
        return None

    def __repr__(self):
        nodes = []
        current = self.head
        while current:
            if current is self.head:
                nodes.append("[Head : %s]" % current.data)
            elif current.next is None:
                nodes.append("[Tail : %s]" % current.data)
            else:
                nodes.append("[%s]" % current.data)
            current = current.next
        return "->".join(nodes)

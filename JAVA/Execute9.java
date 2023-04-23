class Stack {
    int stck[];
    int tos;

    Stack(int size) {
        stck = new int[size];
        tos = -1;
    }

    void push(int item) {
        if (tos == stck.length - 1)
            System.out.println("Stack is full.");
        else
            stck[++tos] = item;
    }

    int pop() {
        if (tos < 0) {
            System.out.println("Stack underflow.");
            return 0;
        } else
            return stck[tos--];
    }
}

class Queue{
    int queue[];
    int front;
    int rear;

    Queue(int size) {
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int element) {
        if (rear == queue.length - 1) {
            System.out.println("Queue overflow");
            return;
        }
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = element;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            System.out.println("Queue underflow");
            return -1;
        }
        return queue[front++];
    }
}

class Execute9 {
    public static void main(String args[]) {
        System.out.println("Adarsh");                     
        Stack mystack = new Stack(5);
        Queue myqueue = new Queue(8);

        for (int i = 0; i < 5; i++)
            mystack.push(i);
        for (int i = 0; i < 8; i++)
            myqueue.enqueue(i);

        System.out.println("Stack in mystack:");
        for (int i = 0; i < 5; i++)
            System.out.println(mystack.pop());
        System.out.println("Queue in myqueue:");
        for (int i = 0; i < 8; i++)
            System.out.println(myqueue.dequeue());
    }
}

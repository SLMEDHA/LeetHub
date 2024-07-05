class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    Node(int val){
        this->data=val;
        next=prev=NULL;
    }
};
class MyCircularDeque {
public:
Node*front;
Node*rear;
int size;
int max_size;
    MyCircularDeque(int k) {
        size=0;
        max_size=k;
        front=rear=NULL;
        
    }
    
    bool insertFront(int value) {
        if(size==max_size)return false;
        Node*temp=new Node(value);
        if(front==NULL){
            front=rear=temp;
        }
        else{
            temp->next=front;
            front->prev=temp;
            front=temp;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
      if(size==max_size) return false;
        Node* temp= new Node(value);
        if(front==NULL){
            front=rear=temp;
        } else{
           rear->next=temp;
            temp->prev=rear;
            rear=temp;
        }
        size++;
        return true;   
    }
    
    bool deleteFront() {
        if(front==NULL)
        return false;
        if(front==rear)
        {
            front=rear=NULL;
        }
        else{
            front=front->next;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(rear==NULL)
            return false;
            if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            rear=rear->prev;
        }
        size--;
        
        return true;
    }
   
    
    int getFront() {
        if(front==NULL)
        return -1;
        return front->data;
    }
    
    int getRear() {
         if(rear==NULL)
            return -1;
        return rear->data;
    }
    
    bool isEmpty() {
         if(front==NULL)
            return true;
        return false;
    }
    
    bool isFull() {
        if(max_size==size)
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
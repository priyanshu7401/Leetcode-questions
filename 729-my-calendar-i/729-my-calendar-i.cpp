class Node
{
public:
int start;
int end;
Node *next;
Node(int start,int end)
{
    this->start=start;
    this->end=end;
    next=NULL;
}
};
class MyCalendar {
    Node*head;
public:
    MyCalendar() 
    {
    head=new Node(-1,0);
    }
    
    bool book(int start, int end) 
    {
        Node*temp=head;
        while(temp->next!=NULL&&start>temp->next->start)
            temp=temp->next;
        if((start>=temp->end&&temp->next==NULL)||(temp->next!=NULL&&start>=temp->end&&end<=temp->next->start))
        {
        Node *ptr=new Node(start,end);
        ptr->next=temp->next;
        temp->next=ptr;
        return true;
        }
         return false;
           
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
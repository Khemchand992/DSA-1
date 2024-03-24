
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    Node *t=new Node;
    
    if(t==NULL)cout<<"OverFlow"<<endl;
    else {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x=-1;
    if(top==NULL)cout<<"Empty stack "<<endl;
    else {
        Node *p=top;
        top=top->next;
        x=p->data;
        delete p;
    }
    return x;
}

int peek(int pos){
    int x=-1;
    if(top!=NULL){
        Node *p=top;
        for(int i=1; i<=pos-1; i++){
            p=p->next;
        }
        x=p->data;
    }
    return x;
}
void display(){
    Node *p=top;
    cout<<"Stack is "<<endl;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    cout<<"Enter how many elements you want to insert"<<endl;
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" numbers one by one"<<endl;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        push(x);
    }
    display();
    
    cout<<"Poped element is "<<pop()<<endl;
    display();
    
    
    cout<<"Element at 3 position is "<<peek(3)<<endl;
    
    return 0;
}

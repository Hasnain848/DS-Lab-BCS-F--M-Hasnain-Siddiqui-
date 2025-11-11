/*Task 5 – Infix to Postfix Conversion using Stack
Write a program to convert an infix expression into postfix form using a stack. Also, evaluate the
postfix expression afterward.*/
#include<iostream>
using namespace std;
class stacknode{
    public:
    char data;
    stacknode*next;
    stacknode(char val){
        data = val;
        next = NULL;
    }
};
class Stack{
    stacknode *top;
    public:
    Stack(){top=NULL;}
    void push(char val){
        stacknode *newnode=new stacknode(val);
        if(!newnode){
            cout<<"Memory allocation failed!"<<endl;
            return;
        }
        newnode->next=top;
        top = newnode;
    }
    char pop(){
        if(top==NULL)
            {cout<<"Stack is Underflow or empty"<<endl;
            return '0';}
        else{
            stacknode *temp = top;
            top=top->next;
            char x = temp->data;
            delete temp;
            return x;
        }
    }
    char peek(){
        if(top==NULL)
            {cout<<"Stack is Underflow or empty"<<endl;
            return '0';}
        else{
            char x = top->data;
            return x;
        }
    }
    bool isEmpty() {
        return top == NULL;
    }
    void display(){
        if(top==NULL)
            {cout<<"(Empty)"<<endl;
            return;}
        else{
            cout<<"=========Displaying Stack========"<<endl;
            stacknode *p=top;
            while(p){
                cout<<p->data<<endl;
                p=p->next;
            }
             cout<<"================================"<<endl;
        }
    }
    char stacktop(){
        if (top==NULL) {
            cout << "(Empty)" << endl;
            return '0';
        }
        return top->data;
    }
    ~Stack()
    {
        stacknode *p = top;
        while(p){
            stacknode *temp=p;
            p=p->next;
            delete temp;
        }
        top =nullptr; 
    }
};
class stacknodeinteger{
    public:
    int data;
    stacknodeinteger*next;
    stacknodeinteger(int val){
        data = val;
        next = NULL;
    }
};
class Stack2{
    stacknodeinteger *top;
    public:
    Stack2(){top=NULL;}
    void push(int val){
        stacknodeinteger *newnode=new stacknodeinteger(val);
        if(!newnode){
            cout<<"Memory allocation failed!"<<endl;
            return;
        }
        newnode->next=top;
        top = newnode;
    }
    int pop(){
        if(top==NULL)
            {cout<<"Stack is Underflow or empty"<<endl;
            return 0;}
        else{
            stacknodeinteger *temp = top;
            top=top->next;
            int x = temp->data;
            delete temp;
            return x;
        }
    }
    ~Stack2()
    {
        stacknodeinteger *p = top;
        while(p){
            stacknodeinteger *temp=p;
            p=p->next;
            delete temp;
        }
        top =nullptr; 
    }
};
int precedence(char c){
    if(c=='^')return 3;
    else if(c=='*' || c== '/')return 2;
    else if(c=='+' || c== '-')return 1;
    else return -1;
}
bool isoperand(char x){
     if(x=='+' || x=='-' || x=='*' || x=='/' ||x=='^')
    return false;
    else
    return true;

}
string InfixtoPostfix(string infix){
    Stack st;
    string postfix="";
    int i=0;
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix+=infix[i++];
        }
        else{
            if(precedence(infix[i])>precedence(st.stacktop())){
                st.push(infix[i++]);
            }
            else {
                postfix+=st.pop();
            }
        }
    }
    while(!st.isEmpty()){
        postfix+=st.pop();
    }
    return postfix;
}
int evaluation(string postfix){
 Stack2 st;
    int i=0;
    int r=0;
    while(postfix[i]!='\0'){
        if(isoperand(postfix[i])){
            st.push(postfix[i]-'0');
        }
        else{
            int x2 = st.pop();
            int x1 = st.pop();
            switch(postfix[i])
            {
                case '+': r=x1+x2; break;
                case '-': r=x1-x2; break;
                case '*': r=x1*x2; break;
                case '/': r=x1/x2; break;            
            }
           st.push(r);
           
        }
        i++;
    }
    return st.pop();
}
int main(){
    string infix="2+1*5";
    string postfix=InfixtoPostfix(infix);
    cout<<"Postfix: "<<postfix<<endl;
    cout<<"Evaluate: "<<evaluation(postfix)<<endl;
}

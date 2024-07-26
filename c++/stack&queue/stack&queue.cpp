#include <iostream>
using namespace std;



class Stack{
    private:
        int top;
        int capacity;
        int* array;


    public:

    Stack(int size){
        capacity = size;
        array = new int[capacity];
        top = -1;
    }

    ~Stack(){
        delete[] array;
    }

    //入栈
    void push(int Val){
        if(top == capacity-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        array[++top] = Val;
    }


    //出栈
    void pop(){
        if(top == -1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top--;
    }
    //判断是否为空
    bool isEmpty(){
        return top==-1;
    }

    //获取栈顶元素
    int peek(){
        if (isEmpty()){
            cout<<"the stack is empty!"<<endl;
            return -250;
        }
        return array[top];
    }
    //获取栈元素个数
    int size(){
        return top+1;
    }
};


int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    if (!stack.isEmpty()) {
        cout << "Top element is: " << stack.peek() << endl;
    }

    cout << "Stack size is: " << stack.size() << endl;

    stack.pop();
    if (!stack.isEmpty()) {
        cout << "Top element after pop is: " << stack.peek() << endl;
    }

    cout << "Stack size after pop is: " << stack.size() << endl;


    
    printf("Press Enter to exit...\n");
    getchar();  // 等待用户输入
    return 0;
}



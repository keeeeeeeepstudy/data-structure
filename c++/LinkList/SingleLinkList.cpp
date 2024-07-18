#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

//通过结构体定义单链表的数据域和指针域
typedef struct LinkNode{

    int data;

    struct LinkNode *Next;

    LinkNode(int val) : data(val), Next(nullptr) {}
}LinkNode;

class LinkList{
    private:
        LinkNode* head;

    public:
        //默认构造函数，在初始化类的时候自动调用,高效初始化
        LinkList() : head(nullptr){};

        //析构函数 在结束使用时自动释放内存
        ~LinkList(){
            LinkNode* temp;
            while (head != nullptr){
                temp = head;
                head = head->Next;
                delete temp;
            }
        }
        

        //尾插法
        void append(int val){
            LinkNode* newNode = new LinkNode(val);
            if (head == nullptr){
                head = newNode;
            }else{
                LinkNode* temp = head;
                while(temp->Next != nullptr){
                    temp = temp->Next;
                    }
                temp->Next = newNode;
            }
        }

        //头插法
        void preappend(int val){
            LinkNode* newNode = new LinkNode(val);
            if (head == nullptr){
                head = newNode;
            }else{
                newNode->Next = head;
                head = newNode;
            }
        }
        void printList(){
            LinkNode* temp = head;
            while (temp != nullptr){
                cout<<temp->data<<"->";
                temp = temp->Next;
            }
            cout<<"nullptr\n";
        }
};

int main() {
    LinkList linklist;

    int data[] = {1, 2, 3, 4, 5};

    for (int val : data) {
        linklist.append(val);  // 尾插法
    }

    cout << "尾插法链表: \n";
    linklist.printList();





    printf("Press Enter to exit...\n");
    getchar();  // 等待用户输入
    return 0;
}

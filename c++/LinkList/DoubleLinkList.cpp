#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

//通过结构体定义单链表的数据域和指针域
typedef struct LinkNode{

    int data;
    struct LinkNode *Prev;
    struct LinkNode *Next;

    LinkNode(int val) : data(val), Next(nullptr),Prev(nullptr) {}
}LinkNode;

class DoubleLinkList{
    private:
        LinkNode* head;
        
    public:
        DoubleLinkList() : head(nullptr){};

        //析构函数 在结束使用时自动释放内存
        ~DoubleLinkList(){
            LinkNode* temp;
            while (head != nullptr){
                temp = head;
                head = head->Next;
                delete temp;
            }
        }

        //头插法插入
        void preappend(int Val){
            LinkNode* NewNode = new LinkNode(Val);
            if (head = nullptr){
                head = NewNode;
            }
            else{
                NewNode->Next = head;
                head->Prev = NewNode;
                head = NewNode;
            }
        }

        //尾插法插入
        void append(int Val){
            LinkNode* NewNode = new LinkNode(Val);
            if(head == nullptr){
                head = NewNode;
            }
            else{
                LinkNode* temp = head;
                while (temp->Next != nullptr){
                    temp = temp->Next;
                }
                temp->Next = NewNode;
                NewNode->Prev = temp;
            }
        }
        //删除节点
        void Delete(int Val){
            if (head == nullptr){
                return;
            }
            //删除头节点
            if (head->data = Val){
                head = head->Next;
            }

        }
};
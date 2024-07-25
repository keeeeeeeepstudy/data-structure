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
        //打印链表
        void printList(){
            LinkNode* temp = head;
            while (temp != nullptr){
                cout<<temp->data<<"<->";
                temp = temp->Next;
            }
            cout<<"nullptr\n";
        }
        //头插法插入
        void preappend(int Val){
            LinkNode* NewNode = new LinkNode(Val);
            if (head == nullptr){
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
            if (head->data == Val){
                head = head->Next;
                head->Prev =nullptr;
            }
            else{
                LinkNode* temp = head;
                while (temp->data !=Val){
                    temp=temp->Next;
                }
                //没找到节点
                if (temp == nullptr){
                    return;
                }
                //非尾节点
                if (temp->Next != nullptr){
                    temp->Prev->Next=temp->Next;
                }
                else{//删除尾节点
                    temp->Prev->Next = nullptr;
                }
            }

        }

        LinkNode* getHead() {
            return head;
        }
};

int main() {
    DoubleLinkList list;

    // 测试头插法
    list.preappend(10);
    list.preappend(20);
    list.preappend(30);
    cout << "After preappending 30, 20, 10: ";
    list.printList();

    // 测试尾插法
    list.append(40);
    list.append(50);
    list.append(60);
    cout << "After appending 40, 50, 60: ";
    list.printList();

    // 测试删除节点
    list.Delete(20);  // 删除中间节点
    cout << "After deleting 20: ";
    list.printList();

    list.Delete(30);  // 删除头节点
    cout << "After deleting 30: ";
    list.printList();


    list.Delete(60);  // 删除尾节点
    cout << "After deleting 60: ";
    list.printList();

    
    printf("Press Enter to exit...\n");
    getchar();  // 等待用户输入
    return 0;
}
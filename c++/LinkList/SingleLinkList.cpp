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
        //打印链表
        void printList(){
            LinkNode* temp = head;
            while (temp != nullptr){
                cout<<temp->data<<"->";
                temp = temp->Next;
            }
            cout<<"nullptr\n";
        }
        //链表长度
        int len(){
            LinkNode* temp = head;
            int length = 0;
            while (temp != nullptr){
                length++;
                temp = temp->Next;
            }
            return length;
        }
        //插入节点
        void Insert(int val,int n){
            LinkNode* newNode = new LinkNode(val);
            int length = len();
            if (n==1){//头节点插入
                newNode->Next = head;
                head = newNode;
            }
            else if(n > length+1 || n<1){//无效位置
                cout<<"invalid position"<<endl;
                delete newNode;
            }
            else{
                LinkNode* temp = head;
                for (int i = 1;i <n-1;i++){
                    temp = temp->Next;
                }
                newNode->Next = temp->Next;
                temp->Next = newNode;
                
            }
        }
        //删除节点
        void Delete(int n){
            int length = len();
            if (n == 1){
                head = head->Next;
            }
            else if(n < 1 || n>length){
                cout<<"invalid position"<<endl;
            }
            else{
                LinkNode* temp = head;
                for (int i = 1;i <n-1;i++){
                    temp = temp->Next;
                }      
                temp->Next = temp->Next->Next;  
            }
        }
        //搜索节点
        int Search(int val){ 
            LinkNode* temp = head;
            int number = 0;
            while (temp != nullptr)
            {
                if (temp->data == val){
                    return number;
                }
                number++;
                temp = temp->Next;
            }
            return -1;
            
        }
};

int main() {
    LinkList linklist;

    int data[] = {1, 2, 3, 4, 5};

    for (int val : data) {
        linklist.append(val);  // 尾插法
    }

    linklist.printList();
    cout << "insert 6\n";
    linklist.Insert(6,6);
    linklist.printList();
    cout << "delete 3\n";
    linklist.Delete(3);
    linklist.printList();

    printf("Press Enter to exit...\n");
    getchar();  // 等待用户输入
    return 0;
}

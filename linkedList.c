#include <stdio.h> 

// 链表

typedef struct Node{
	// 双链表		
	struct Node *prev;	
	struct Node *next;
	char *payload;
}  Node;

// 初始化一个链表
Node* init_linedList(){
    Node node;
    Node *result = &node;
    result->prev = 0;
    result->next = 0;
    result->payload = "TOP";
}

// 获取链表中的元素值

Node* GetElement(struct Node *linked_list, int index){
    Node *p = linked_list;
    int count  = 0;
	while (count != index){
		p = p->next;
		count++;	
	}

	return p;
}


// 插入一个节点
void insert_node(Node *linked_list , int index, char *payload){
   Node insert;
   insert.payload = payload;
   Node *insert_node= &insert;
   Node *old = GetElement(linked_list,index);
   // inset prev/next = 0
   insert_node->prev = old->prev;
   insert_node->next = old;

   old->prev = insert_node;
}  

// 删除一个节点
void delete_node(Node *linked_list,int index){
    Node *del = GetElement(linked_list,index);
    Node next = del->next;
    next->prev = del->prev;
    del->prev->next = del->next;
    del = 0;
    
}

/*int main(){
	// 声明一个node类型的变量
	Node test;
	// 声明一个node类型的指针
	// Node *test
	// 空的指向 test -> 0x0
	// 先声明一个node类型的变量，把指针指向变量；
	Node *node = &test;
	char *text = "hello lzf";
	node->payload = text;
   	puts(GetElement(node,0));	
}*/

int main(){
    Node *linkedList = init_linedList();
    insert_node(linkedList,0,"test");
    
}

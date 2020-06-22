#include <iostream>
#include <string>

struct Node{
	int value;
	struct Node* next;
};

Node *createList_array(int *a, int n){
	Node *root = new Node();
	Node *pnode = root;
	
	for (int i = 0; i < n - 1; ++i){
		root->value = a[i];//当前节点
		root->next = NULL;

		Node *p = new Node();//下一个结点
		p->value = a[i + 1];
		p->next = NULL;

		root->next = p;// 连接 当前节点 与 下一个结点
		root = root->next;
	}
	root->next = NULL;//这一句 最重要！！
	return pnode;
}

void disp(Node* node){
	std::cout << "--------------------1" << std::endl;
	if (node == NULL) return;
	while (node != NULL){
		std::cout << node->value;
		if (node->next)	std::cout << "->";
		node = node->next;
	}
	std::cout << std::endl;
}

void disp2(Node* node){
	std::cout << "--------------------2" << std::endl;
	if (node == NULL) return;
	std::cout << node->value;
	while (node->next != NULL){
		std::cout << "->";
		node = node->next;
		std::cout << node->value;
	}
	std::cout << std::endl;
}

int main(){
	int a[] = { 1, 3, 5, 7, 9 };
	int n = sizeof(a) / sizeof(a[0]);
	Node *pnode = createList_array(a, n);
	disp(pnode);
	disp(pnode);

	disp2(pnode);
	disp2(pnode);
}

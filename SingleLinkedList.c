#include <stdio.h>
#include <stdlib.h>



#define OK 1
#define ERROR 0
typedef int Status;


typedef struct LNode{
	char data;				// 数据域
	struct LNode *next;		// 指针域
}LNode;



// 创建单链表
LNode* CreateList_L(int n){
	LNode *p = (LNode*) malloc(sizeof(LNode));

	LNode *cur_node = p;

	for (int i = 0; i < n; ++i)
	{
		LNode *node = (LNode*)malloc(sizeof(LNode));
		if(node){
			scanf("%c", &(node->data));
			node->next = NULL;
			cur_node->next = node;
			cur_node = node;
		}
		else
		{
			printf("创建节点失败\n");

		}
		
	}
	return p;
};


// 插入
Status ListInsert_L(LNode *L, int i, char ele){

	int pos = 0;
	LNode *p = L;

	while(p&&pos<i-1){
		p = p->next;
		pos++;
	}

	if (!p || pos > i-1){
		return ERROR;
	}

	LNode *node = malloc(sizeof(LNode));
	node->data = ele;
	node->next = p->next;
	p->next = node;
	return OK;

};


void display(LNode *L){
	LNode *cur_node = L;
	while(cur_node->next){
		cur_node = cur_node->next;
		printf("%c ", cur_node->data);
	}
	printf("\n");
};


// 带头结点单链表 删除第i个元素 并返回
Status ListDelete_L(LNode *L, int i, char *ele){
	int pos = 0;
	LNode *cur_node = L;
	while(cur_node->next&&pos<i-1){
		pos++;
		cur_node = cur_node->next;
	}

	if(!cur_node || pos > i-1){
		return ERROR;
	}
	LNode *q = cur_node->next;
	cur_node->next = q->next;
	*ele = q->data;
	free(q);
	return OK;

}



int main(int argc, char const *argv[])
{

	LNode *L = NULL;
	
	L = CreateList_L(5);
	display(L);

	printf("在2位置添加Y\n");
	ListInsert_L(L, 2, 'Y');
	display(L);

	char e;
	printf("删除3位置的数据\n");
	ListDelete_L(L, 3, &e);
	display(L);
	printf("返回值为：%c\n", e);
	return 0;
}
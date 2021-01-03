#include <stdlib.h>
#include <stdio.h>

/*
顺序表是 用顺序存储实现的线性表

顺序表的特点:
1. 支持随机访问， 可以在O(1)的时间找到第i个元素
2. 储存密度高， 每个节点只存储数据元素
3. 扩展容量不方便（即便采用动态分配的方式实现， 拓展长度的时间复杂度也比较高）

顺序表的实现 -- 动态分配
动态分配的实现：
用一个指针指向顺序表的数据域，扩容的时候重新申请一块更大的区域
然后将旧区域的数据复制复制到新的区域

*/


#define InitSize 5		// 定义默认最大长度


typedef struct {
	int *data;		// 动态分配的指针
	int Maxsize;
	int length;

}SeqList;



void InitList(SeqList *L){
	L->data = (int *)malloc(InitSize*sizeof(int));	// 使用malloc申请一块连续的空间
	L->Maxsize = InitSize;
	L->length = 0;

};


// 扩容顺序表， 
void IncreaseSize(SeqList *L, int len){
	int *p = L->data;
	L->data = (int *)malloc((L->Maxsize+len)*sizeof(int));
	for (int i = 0; i < L->length; ++i)
	{
		L->data[i] = p[i];			// 将旧区域的数据复制到新的区域。 全体搬家，开销挺大的。
	}
	L->Maxsize = L->Maxsize + len;
	free(p);	// 释放原来的内存空间
};


int ListInsert(SeqList *L, int pos, int elem){
	if(pos <1 || pos > L->length+1){
		return 0;
	}
	if(L->length >= L->Maxsize){
		return 0;
	}

	for (int i = L->length; i >= pos; --i)
	{
		L->data[i] = L->data[i-1];
	}
	L->data[pos-1] = elem;
	L->length++;
	return 1;

};


void ListPrint(SeqList L){
	for (int i = 0; i < L.length; ++i)
	{
		printf("data[%d] is %d\n",i, L.data[i] );
	}
	printf("\n");
};



int main(int argc, char const *argv[])
{
	SeqList L;

	InitList(&L);
	printf("InitSzie is 5, add 6 elem\n");
	ListInsert(&L, 1, 100);
	ListInsert(&L, 2, 200);
	ListInsert(&L, 3, 300);
	ListInsert(&L, 4, 400);
	ListInsert(&L, 5, 500);
	ListInsert(&L, 6, 600);
	ListPrint(L);

	printf("after increasesize\n");
	IncreaseSize(&L, 5);
	ListInsert(&L, 6, 600);
	ListInsert(&L, 7, 700);
	ListInsert(&L, 8, 800);
	ListPrint(L);
	return 0;
}

























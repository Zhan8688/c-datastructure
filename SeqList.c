#include <stdio.h>

// 顺序表的实现， 静态分配法 预先分配一块固定大小的空间
// 这种方法 顺序表的空间刚开始确定后就无法更改

#define MaxSize 10	// 最大长度

typedef struct{
	int data[MaxSize];		// 用静态的数组存放数据， 本例中ElemType为int
	int length;				// 顺序表当前长度
}SeqList;


// 初始化一个顺序表
void InitList(SeqList *L){
	for(int i=0; i<MaxSize; i++)
	{
		L->data[i]=0;		// 将所有数据元素设置为默认初始值, 防止内存中遗留”脏数据“
	};
	L->length = 0;			// 将顺序表初始化长度为0
};


// 插入操作 在L的位序pos除插入元素e
// 最好时间复杂度是O(1) 最坏时间复杂度是O(n) 平均时间复杂度是O(n/2)
int ListInsert(SeqList *L, int pos, int elem){
	if(pos <1 || pos > L->length+1){
		return 0;
	}
	if(L->length >= MaxSize){
		return 0;
	}

	for (int i = L->length; i >= pos; --i)
	{
		L->data[i] = L->data[i-1];
	}
	L->data[pos-1] = elem;
	L->length++;
	return 1;

}



int ListDelete(SeqList *L, int pos, int *e){
	if( pos > L->length || pos < 1){
		return 0;
	}
	if(L->length == 0){
		return 0;
	}

	*e = L->data[pos-1];
	for(int i = pos; i < L->length; ++i)
	{
		L->data[i-1] = L->data[i];
	}
	L->length--;
	return 1;
}

void ListPrint(SeqList L){
	for (int i = 0; i < L.length; ++i)
	{
		printf("data[%d] is %d\n",i, L.data[i] );
	}
	printf("\n");
}

int GetElem(SeqList L, int pos){
	if(pos > L.length){
		return 0;
	}

	return L.data[pos-1];
}

int LocateElem(SeqList L, int ele){
	for (int i = 0; i < L.length; ++i)
	{
		if(L.data[i] == ele){
			return i+1;
		}
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	SeqList L;
	InitList(&L);
	ListInsert(&L, 1, 100);
	ListInsert(&L, 2, 200);
	ListInsert(&L, 3, 300);
	ListInsert(&L, 4, 400);

	ListPrint(L);

	printf("after insert 3 30\n");
	ListInsert(&L, 3, 30);
	ListPrint(L);

	int e = -1;

	ListDelete(&L, 4, &e);
	printf("e is %d\n", e);
	printf("after delete %d \n", e);
	ListPrint(L);


	printf("pos 4 is %d\n", GetElem(L, 4));

	printf("200 is locate %d\n", LocateElem(L, 200));

	return 0;
}


















#include<stdio.h>
#include<malloc.h>
 
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//头插法
CreLinkListHead(int n)
{
    int i,a;
    LNode *L;
    L=(LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请输入");
    for(i=0;i<n;i++)
    {
        LNode *p;
        p=(LNode *)malloc(sizeof(LNode));
        scanf("%d",&a);
        p->data = a;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

//尾插法
CreLinkListTail(int n)
{
    int a;
    LNode *L;
    L=(LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s;
    s=L;
    printf("请输入:");
    while(n--)
    {
        scanf("%d",&a);
        LNode *p;
        p=(LNode *)malloc(sizeof(LNode));
        p->data = a;
        s->next = p;
        s=p;
    }
    s->next = NULL;
    return L;
}

//在i位置上插入元素
void InsLinkList(LinkList L,int i,ElemType x)
{
    LinkList p;
    p=L;
    int j;
    j=1;
    while(j<i)
    {
        p=p->next;
        j++;
    }
    LNode *s;
    s=(LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

//删除i位置上的元素
void DelLinkList(LinkList L,int i)
{
    int j;
    LinkList p,q;
    p=L;
    j=1;
    while(j<i)
    {
        p=p->next;
        j++;
    }
    q=p->next;
    p->next = p->next->next;
    free(q);
}
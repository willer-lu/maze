#include <stdio.h>
#include <stdlib.h>
//5.复数四则运算
//问题描述
//设计一个简单的复数四则运算计算器。
//实验要求
//1)采用顺序表或链表等数据结构。
//2)输入并生成复数。
//3)输出运算结果的标准复数形式。a+bi
typedef struct LNode{
    int a;//实部
    int b;//虚部
    struct LNode*next;
}LNode,*LinkList;
LinkList *CreateList(LinkList*L)
{
    int a,b;
     LinkList r,s;
    *L=(LinkList)malloc(sizeof(LNode));
    r=*L;
    printf("请输入前一复数的实部和虚部，用空格分隔：\n");
    scanf("%d %d",&a,&b);
    s=(LinkList)malloc(sizeof(LNode));
            s->a=a;
            s->b=b;
            s->next=NULL;
            r->next=s;

        return L;

}
void getnum(LinkList*L){
    LinkList r= *L;LinkList s;
    int a,b;
     while(r->next!=NULL)r=r->next;
    printf("请输入下一复数的实部和虚部，用空格分隔：\n");
    scanf("%d %d",&a,&b);
    s=(LinkList)malloc(sizeof(LNode));
            s->a=a;
            s->b=b;
            s->next=NULL;
            r->next=s;

}
void printnum(LinkList L)//输出复数，即当前指针所指的结点
{

             LinkList r=L;
             while(r->next!=NULL)r=r->next;
            if(r->a==0&&r->b!=0)printf("运算结果为%di\n",r->b);
            if(r->a==0&&r->b==0)printf("运算结果为0\n");
            if(r->a!=0&&r->b<0)printf("运算结果为%d%di\n",r->a,r->b);
            if(r->a!=0&&r->b>0)printf("运算结果为%d+%di\n",r->a,r->b);
            if(r->a!=0&&r->b==0)printf("运算结果为%d\n",r->a);

}
void releaseList(LinkList p)
{
	if(NULL == p->next)
		 free(p);
	else
	{
		releaseList(p->next);
		 free(p);
	}
}//释放空间
void plusnum(LinkList *L){
   LinkList p=*L,s;
   int suma=0,sumb=0;
   if(!p||!p->next)
   {
       printf("wrong!");

   }
   while(p->next->next!=NULL)
   {
       p=p->next;
   }


       suma+=p->a;
       sumb+=p->b;
       p=p->next;
       suma+=p->a;
       sumb+=p->b;

   s=(LinkList)malloc(sizeof(LNode));
            s->a=suma;
            s->b=sumb;
            s->next=NULL;
            p->next=s;

}//加法运算
void minusnum(LinkList *L){
    LinkList p=*L,s;
   int suma,sumb;
   if(!p||!p->next)
   {
       printf("wrong!");

   }
   while(p->next->next!=NULL)
   {
       p=p->next;
   }
       suma=p->a;
       sumb=p->b;
       p=p->next;
       suma-=p->a;
       sumb-=p->b;
   s=(LinkList)malloc(sizeof(LNode));
            s->a=suma;
            s->b=sumb;
            s->next=NULL;
            p->next=s;

}//减法运算
void multinum(LinkList *L){
     LinkList p=*L,s;
   int suma,sumb,a,b;
   if(!p||!p->next)
   {
       printf("wrong!");

   }
   while(p->next->next!=NULL)
   {
       p=p->next;
   }
       suma=p->a;
       sumb=p->b;
       p=p->next;
        a=p->a;
        b=p->b;
        int t=suma;
        suma=suma*a-sumb*b;
        sumb=t*b+sumb*a;
     s=(LinkList)malloc(sizeof(LNode));
            s->a=suma;
            s->b=sumb;
            s->next=NULL;
            p->next=s;

   }//乘法运算
void calculate(){
          system("cls");
          int b;
           LinkList a;
           a=*CreateList(&a);
           getnum(&a);
           printf("请输入你想进行的运算:\n");
        char c;
        scanf("%c",&c);
        scanf("%c",&c);
           switch(c){
           case '+':plusnum(&a);break;
           case '-':minusnum(&a);break;
           case '*':multinum(&a);break;
           default:break;
            }
            printnum(a);
            printf("是否继续计算？\n");
            printf(" 1.在该结果上继续计算\n");
            printf(" 2.终止本次计算\n");
			scanf("%d",&b);
			 while(b==1){getnum(&a);
                         printf("请输入你想进行的运算:\n");
                         scanf("%c",&c);//消去空格的影响
                         scanf("%c",&c);
                       switch(c){
                       case '+':plusnum(&a);break;
                       case '-':minusnum(&a);break;
                       case '*':multinum(&a);break;
                      default:break;
                       } printnum(a);
                       printf("是否继续计算？\n");
                        printf(" 1.在该结果上继续计算\n");
                         printf(" 2.终止本次计算\n");
			            scanf("%d",&b);
                       }
			    if(b==2){releaseList(a);printf("感谢使用");}
                system("pause");
            }
int main()
{


    system("color F0");
    while(1){ system("cls");
    printf("\n\n\n\n");
			printf(" ***********************************************\n");
			printf(" ^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^ ^_^\n");
			printf(" ***********************************************\n");
			printf("  ____________________________________________ \n");
			printf("┃                                            ┃\n");
            printf("┃               复数计算器                   ┃\n");
			printf("┃____________________________________________┃\n");
			printf("***********************************************\n");
			printf("***********************************************\n");
			printf("**            1.进入计算                     **\n");
			printf("**            2.退出计算器                   **\n");
			printf("***********************************************\n");
			printf("^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^ ^_^\n");
			printf("***********************************************\n");
			printf("               选择操作：");
			int m;
			scanf("%d",&m);
			switch(m){
			    case 1:calculate();break;
			    case 2:{printf("感谢您的使用。");exit(0);break;}
			    default:break;}
              }



          return 0;
}

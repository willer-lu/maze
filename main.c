#include <stdio.h>
#include <stdlib.h>
//5.������������
//��������
//���һ���򵥵ĸ������������������
//ʵ��Ҫ��
//1)����˳������������ݽṹ��
//2)���벢���ɸ�����
//3)����������ı�׼������ʽ��a+bi
typedef struct LNode{
    int a;//ʵ��
    int b;//�鲿
    struct LNode*next;
}LNode,*LinkList;
LinkList *CreateList(LinkList*L)
{
    int a,b;
     LinkList r,s;
    *L=(LinkList)malloc(sizeof(LNode));
    r=*L;
    printf("������ǰһ������ʵ�����鲿���ÿո�ָ���\n");
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
    printf("��������һ������ʵ�����鲿���ÿո�ָ���\n");
    scanf("%d %d",&a,&b);
    s=(LinkList)malloc(sizeof(LNode));
            s->a=a;
            s->b=b;
            s->next=NULL;
            r->next=s;

}
void printnum(LinkList L)//�������������ǰָ����ָ�Ľ��
{

             LinkList r=L;
             while(r->next!=NULL)r=r->next;
            if(r->a==0&&r->b!=0)printf("������Ϊ%di\n",r->b);
            if(r->a==0&&r->b==0)printf("������Ϊ0\n");
            if(r->a!=0&&r->b<0)printf("������Ϊ%d%di\n",r->a,r->b);
            if(r->a!=0&&r->b>0)printf("������Ϊ%d+%di\n",r->a,r->b);
            if(r->a!=0&&r->b==0)printf("������Ϊ%d\n",r->a);

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
}//�ͷſռ�
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

}//�ӷ�����
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

}//��������
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

   }//�˷�����
void calculate(){
          system("cls");
          int b;
           LinkList a;
           a=*CreateList(&a);
           getnum(&a);
           printf("������������е�����:\n");
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
            printf("�Ƿ�������㣿\n");
            printf(" 1.�ڸý���ϼ�������\n");
            printf(" 2.��ֹ���μ���\n");
			scanf("%d",&b);
			 while(b==1){getnum(&a);
                         printf("������������е�����:\n");
                         scanf("%c",&c);//��ȥ�ո��Ӱ��
                         scanf("%c",&c);
                       switch(c){
                       case '+':plusnum(&a);break;
                       case '-':minusnum(&a);break;
                       case '*':multinum(&a);break;
                      default:break;
                       } printnum(a);
                       printf("�Ƿ�������㣿\n");
                        printf(" 1.�ڸý���ϼ�������\n");
                         printf(" 2.��ֹ���μ���\n");
			            scanf("%d",&b);
                       }
			    if(b==2){releaseList(a);printf("��лʹ��");}
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
			printf("��                                            ��\n");
            printf("��               ����������                   ��\n");
			printf("��____________________________________________��\n");
			printf("***********************************************\n");
			printf("***********************************************\n");
			printf("**            1.�������                     **\n");
			printf("**            2.�˳�������                   **\n");
			printf("***********************************************\n");
			printf("^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^  ^_^ ^_^\n");
			printf("***********************************************\n");
			printf("               ѡ�������");
			int m;
			scanf("%d",&m);
			switch(m){
			    case 1:calculate();break;
			    case 2:{printf("��л����ʹ�á�");exit(0);break;}
			    default:break;}
              }



          return 0;
}

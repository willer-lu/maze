#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//������������
//��һ��M��N���Թ���0��1�ֱ��ʾͨ�����ϰ���
//��ʵ��Ҫ��
//��Ƴ���ʵ�������ڵ����ڵ�����ͨ����
//��1������ջ�����ݽṹ��
//��2��Ӧ����ٷ����ݲ�����⡣
//��3�������������ͨ·�����·����
#define MaxSize 100//˳��ջ�Ĵ�С
typedef struct
{
    int i;//��ǰ�����к�
    int j;//��ǰ�����к�
    int di;//��һ�����ߵ����ڷ���ķ�λ��
}Box;//���巽������
typedef struct
{
    Box data[MaxSize];
    int top;//ջ��ָ��
}StType;//����˳��ջ����
int M=10;//����
int N=10;//����
int mg[10][10]=//���ö�ά�������Թ�
{ {1,1,1,1,1,1,1,1,1,1},
  {1,0,1,1,0,0,0,1,0,1},
  {1,0,1,0,0,0,0,1,0,1},
  {1,0,1,0,0,0,1,0,0,1},
  {1,0,1,0,1,1,0,0,0,1},
  {1,0,0,0,1,0,0,0,0,1},
  {1,0,1,0,0,0,0,1,0,1},
  {1,0,1,1,1,1,1,0,0,1},
  {1,1,0,0,0,0,0,1,0,1},
  {1,1,1,1,1,1,1,1,1,1}
  };
void initmaze(int M,int N)//��ӡ�Թ�
{
     int a,b;
     printf("�Թ�Ϊ:\n");
     for(a=0;a<M;a++){
     for(b=0;b<N;b++)printf(mg[a][b]?"#":" ");//��#��ʾ�ϰ����ǽ�ڣ��հױ�ʾ��ͨ��
        printf("\n");}
}
int mgpath(int xi,int yi,int xe,int ye)//���·��Ϊ��(xi,yi)->(xe,ye)
{
    int i,j,k,h1=0,h2=0,di,p[100],find,min=0,count=0;
    if(mg[xi][yi]==1||mg[xe][ye]==1)return 0;
    StType st;//����ջst
    st.top=-1;//��ʼ��ջ��ָ��
    st.top++;//��ʼ�����ջ
    st.data[st.top].i=xi;
    st.data[st.top].j=yi;
    st.data[st.top].di=-1;
    mg[xi][yi]=-1;//�����ظ��ߵ��÷���
    while(st.top>-1)//ջ��Ϊ��ʱѭ��
    {
        i=st.data[st.top].i;//ȡ��ǰ���ڷ��������
        j=st.data[st.top].j;
        di=st.data[st.top].di;//ȡջ������
        find=0;//��ʼ��find
        while(di<4&&find==0)//վ��һ�����߷���
        {
            di++;
            switch(di)
            {
            case 0://ȡ��ǰ�����ϲ�ķ�����Ϊ��һ����
                i=st.data[st.top].i-1;
                j=st.data[st.top].j;
                break;
            case 1://ȡ��ǰ�����Ҳ�ķ�����Ϊ��һ����
                i=st.data[st.top].i;
                j=st.data[st.top].j+1;
                break;
            case 2://ȡ��ǰ�����²�ķ�����Ϊ��һ����
                i=st.data[st.top].i+1;
                j=st.data[st.top].j;
                break;
            case 3://ȡ��ǰ�������ķ�����Ϊ��һ����
                i=st.data[st.top].i;
                j=st.data[st.top].j-1;
                break;
            }
            if(mg[i][j]==0)//˵���÷��鲻��ǽ��
                find=1;//����һ���������ڷ���
        }//ȡ�鵱ǰ��������з���
        if(find==1)//�ҵ�����һ�����߷���
        {
            st.data[st.top].di=di;//�޸�ԭջ��Ԫ�ص�diֵΪ��ǰ����Ӧ���ߵķ���
            st.top++;//��һ�����߷����ջ
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=-1;
            mg[i][j]=-1;//�����ظ��ߵ��÷���
        }
        else//û��·����������ջ
        {
            mg[st.data[st.top].i][st.data[st.top].j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
            st.top--;//���÷�����ջ
        }
         if(i==xe&&j==ye)//�ҵ����ڣ����·��

        {
            count++;
             if(min==0||st.top<=min){
            if(st.top<min)h2=0;//�����и��̵�·��
            if(st.top==min)h2++;//��h2����¼������ͬ��·��
             min=st.top;
             p[h1]=count;
             h1++;
             }
            printf("��%d��·�����£�\n",count);
            for(k=0; k<=st.top; k++)
            {
                printf("(%d,%d)",st.data[k].i,st.data[k].j);//��ջ�е�����Ԫ���������
                if((k+1)%8==0)printf("\n");
            }printf("\n");
            mg[st.data[st.top].i][st.data[st.top].j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
            st.top--;//���÷�����ջ
            }
    }
//�������Ҫ�����������·��
    if(count>0){
            k=h1;
            h1=h1-h2;//�ҵ���һ��������ͬ��·���洢��λ��
        while(h1<k){

        printf("��%d�� ",p[h1-1]);
         h1++;}
        printf("��%d�� ",p[k-1]);
            printf("������·��\n");return 1;}
          else return 0;
}
void create(){
system("cls");
int a,b,c=0;
printf("�������½��Թ�������������(4-10)���Կո�ָ�\n");
scanf("%d %d",&M,&N);
while(M<4||N<4||M>10||N>10){printf("���벻����Ҫ������������\n");scanf("%d %d",&M,&N);}
printf("�������Թ���0��ʾͨ·��1��ʾǽ�ڣ�\n");
for(a=0;a<M;a++)for(b=0;b<N;b++){scanf("%d",&mg[a][b]);   //�����Թ���Ӧ����������
if(mg[a][b]!=0&&mg[a][b]!=1)c++;}
for(b=0;b<N;b++)if(mg[0][b]==0||mg[M-1][b]==0)c++;
for(a=0;a<M;a++)if(mg[a][0]==0||mg[a][N-1]==0)c++;
while(c!=0){printf("�Թ����벻����Ҫ������������\n");
c=0;
for(a=0;a<M;a++)for(b=0;b<N;b++)scanf("%d",&mg[a][b]);   //�����Թ���Ӧ����������
for(b=0;b<N;b++)if(mg[0][b]==0||mg[M-1][b]==0)c++;
for(a=0;a<M;a++)if(mg[a][0]==0||mg[a][N-1]==0)c++;}
initmaze(M,N);
system("pause");

}
void judge(){
        system("cls");
        initmaze(M,N);
        if(!mgpath(1,1,M-2,N-2))printf("�޽�\n");
        system("pause");}
int main()
{
    system("color F0");
    while(1){
    int w;
   system("cls");
   printf("**********     ��ӭʹ���Թ����           ********\n");
   printf("***************�½��Թ��밴:1   ******************\n");
   printf("***************    �Թ����:2   ******************\n");
   printf("***************    �˳��밴:3   ******************\n");
   printf("**************************************************\n");
   printf("��������ѡ��:");
    scanf("%d",&w);
    switch(w)//�������WΪ1��2,���������
    {   case 1:{create();break;}
        case 2:{judge();break;}
        case 3: printf("��ӭ�´�ʹ��!");return 0;
        break;
       default: break;
   }
    }return 0;
}

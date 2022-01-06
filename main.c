#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//【问题描述】
//设一个M×N的迷宫，0和1分别表示通道和障碍。
//【实验要求】
//设计程序实现求从入口到出口的任意通道。
//（1）采用栈等数据结构。
//（2）应用穷举法回溯策略求解。
//（3）尝试求解所有通路或最佳路径。
#define MaxSize 100//顺序栈的大小
typedef struct
{
    int i;//当前方块行号
    int j;//当前方块列号
    int di;//下一个可走的相邻方块的方位号
}Box;//定义方块类型
typedef struct
{
    Box data[MaxSize];
    int top;//栈顶指针
}StType;//定义顺序栈类型
int M=10;//行数
int N=10;//列数
int mg[10][10]=//利用二维数组存放迷宫
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
void initmaze(int M,int N)//打印迷宫
{
     int a,b;
     printf("迷宫为:\n");
     for(a=0;a<M;a++){
     for(b=0;b<N;b++)printf(mg[a][b]?"#":" ");//用#表示障碍物或墙壁，空白表示可通行
        printf("\n");}
}
int mgpath(int xi,int yi,int xe,int ye)//求解路径为：(xi,yi)->(xe,ye)
{
    int i,j,k,h1=0,h2=0,di,p[100],find,min=0,count=0;
    if(mg[xi][yi]==1||mg[xe][ye]==1)return 0;
    StType st;//定义栈st
    st.top=-1;//初始化栈顶指针
    st.top++;//初始方块进栈
    st.data[st.top].i=xi;
    st.data[st.top].j=yi;
    st.data[st.top].di=-1;
    mg[xi][yi]=-1;//避免重复走到该方块
    while(st.top>-1)//栈不为空时循环
    {
        i=st.data[st.top].i;//取当前所在方块的坐标
        j=st.data[st.top].j;
        di=st.data[st.top].di;//取栈顶方块
        find=0;//初始化find
        while(di<4&&find==0)//站下一个可走方块
        {
            di++;
            switch(di)
            {
            case 0://取当前方块上侧的方块作为下一方块
                i=st.data[st.top].i-1;
                j=st.data[st.top].j;
                break;
            case 1://取当前方块右侧的方块作为下一方块
                i=st.data[st.top].i;
                j=st.data[st.top].j+1;
                break;
            case 2://取当前方块下侧的方块作为下一方块
                i=st.data[st.top].i+1;
                j=st.data[st.top].j;
                break;
            case 3://取当前方块左侧的方块作为下一方块
                i=st.data[st.top].i;
                j=st.data[st.top].j-1;
                break;
            }
            if(mg[i][j]==0)//说明该方块不是墙壁
                find=1;//找下一个可走相邻方块
        }//取遍当前方块的所有方向
        if(find==1)//找到了下一个可走方块
        {
            st.data[st.top].di=di;//修改原栈顶元素的di值为当前方块应该走的方向
            st.top++;//下一个可走方块进栈
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=-1;
            mg[i][j]=-1;//避免重复走到该方块
        }
        else//没有路径可走则退栈
        {
            mg[st.data[st.top].i][st.data[st.top].j]=0;//让该位置变为其他路径可走方块
            st.top--;//将该方块退栈
        }
         if(i==xe&&j==ye)//找到出口，输出路径

        {
            count++;
             if(min==0||st.top<=min){
            if(st.top<min)h2=0;//发现有更短的路径
            if(st.top==min)h2++;//用h2来记录步数相同的路径
             min=st.top;
             p[h1]=count;
             h1++;
             }
            printf("第%d条路径如下：\n",count);
            for(k=0; k<=st.top; k++)
            {
                printf("(%d,%d)",st.data[k].i,st.data[k].j);//将栈中的所有元素依序输出
                if((k+1)%8==0)printf("\n");
            }printf("\n");
            mg[st.data[st.top].i][st.data[st.top].j]=0;//让该位置变为其他路径可走方块
            st.top--;//将该方块退栈
            }
    }
//输出符合要求的所有最优路径
    if(count>0){
            k=h1;
            h1=h1-h2;//找到第一个步数相同的路径存储的位置
        while(h1<k){

        printf("第%d条 ",p[h1-1]);
         h1++;}
        printf("第%d条 ",p[k-1]);
            printf("是最优路径\n");return 1;}
          else return 0;
}
void create(){
system("cls");
int a,b,c=0;
printf("请输入新建迷宫的行数和列数(4-10)，以空格分隔\n");
scanf("%d %d",&M,&N);
while(M<4||N<4||M>10||N>10){printf("输入不符合要求，请重新输入\n");scanf("%d %d",&M,&N);}
printf("请输入迷宫（0表示通路，1表示墙壁）\n");
for(a=0;a<M;a++)for(b=0;b<N;b++){scanf("%d",&mg[a][b]);   //输入迷宫对应的数组数据
if(mg[a][b]!=0&&mg[a][b]!=1)c++;}
for(b=0;b<N;b++)if(mg[0][b]==0||mg[M-1][b]==0)c++;
for(a=0;a<M;a++)if(mg[a][0]==0||mg[a][N-1]==0)c++;
while(c!=0){printf("迷宫输入不符合要求，请重新输入\n");
c=0;
for(a=0;a<M;a++)for(b=0;b<N;b++)scanf("%d",&mg[a][b]);   //输入迷宫对应的数组数据
for(b=0;b<N;b++)if(mg[0][b]==0||mg[M-1][b]==0)c++;
for(a=0;a<M;a++)if(mg[a][0]==0||mg[a][N-1]==0)c++;}
initmaze(M,N);
system("pause");

}
void judge(){
        system("cls");
        initmaze(M,N);
        if(!mgpath(1,1,M-2,N-2))printf("无解\n");
        system("pause");}
int main()
{
    system("color F0");
    while(1){
    int w;
   system("cls");
   printf("**********     欢迎使用迷宫求解           ********\n");
   printf("***************新建迷宫请按:1   ******************\n");
   printf("***************    迷宫求解:2   ******************\n");
   printf("***************    退出请按:3   ******************\n");
   printf("**************************************************\n");
   printf("输入您的选择:");
    scanf("%d",&w);
    switch(w)//若输入的W为1或2,则继续程序
    {   case 1:{create();break;}
        case 2:{judge();break;}
        case 3: printf("欢迎下次使用!");return 0;
        break;
       default: break;
   }
    }return 0;
}

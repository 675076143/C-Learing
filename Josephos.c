#include<stdio.h>
#include<stdlib.h>
//声明循环链表结构体
typedef struct LNode
{
      int num;//数据域
      struct LNode *next;//结构体指针
}LNode;//结点类型
 
//创建结点
LNode *Create_node(int Lnum)
{
      LNode *Lp;//创建结点指针
      Lp=(LNode *)malloc(sizeof(LNode));//分配动态储存空间
      Lp->num=Lnum;//*Lp指向num，把num的值传给Lnum
      Lp->next=NULL;//*Lp指向下一个元素结点为空，确定*Lp是头结点指针
      return Lp;//返回头结点指针
}
 
//创建循环链表
LNode *Create_Linklist(LNode *pHead, int Lsum)
{
      int k;
      LNode *p, *temp;//创建两个指针
      for(k=1;k<=Lsum;k++)//遍历整个链表
      {
             p=Create_node(k);
             //如果链表为空，创建链表第一个结点，其next指针指向自身
             if(pHead==NULL)
             {
                    temp=p; //把p的值传给temp
                    pHead=p; //把p的值传给pHead
                    temp->next=pHead; //让*temp指向的下一个位置为pHead
             }
             //否则，执行插入节点操作
             else
             {
                    p->next=temp->next;//空白指针跟着*p后面，一个接一个插入
                    temp->next=p;
                    temp=p; //把p的值再传给temp
             }
      }
//测试是否生成循环链表成功！
 
      p=pHead;
      k=1;//初始化k的值
      while(p->next!=pHead)//用循环输出链表中的元素
      {
             printf("第%d个小孩的编号为：%d\n",k,p->num);
             p=p->next;//指针移向下一个位置
             k++;
      }
      printf("第%d个小孩的编号为：%d\n\n",k,p->num);//确保最后一个元素能显示出来
 
      return pHead;//返回头指针
}
 
//执行出列操作
void Delete_Linklist(LNode *pHead,int Lstart, int Ldel)
{
      int i,count=1;//count为计数器
      LNode *p, *temp;
      p=pHead;
      //找到第M个猴子所在的位置
      for(i=1;i<Lstart;i++)
             p=p->next;
      //只剩1个结点时终止循环
      while(p->next!=p)
      {
             //找到要出列的猴子的位置
             for(i=1;i<Ldel;i++)
             {
                    temp=p;
                    p=p->next;
             }
             //执行出列操作
             temp->next=p->next;//让*temp指向*p后面的结点
             printf("第%d个出列的猴子的编号为：%d\n",count,p->num);
             free(p);//释放*p
             count++;
             //出列者的下一个猴子作为新的第一个报数者
             p=temp->next;
      }
      printf("第%d个出列的猴子的编号为：%d\n",count,p->num);
      free(p);
      //所有人均出列，头结点释放后赋空值，避免出现悬垂指针
      pHead=NULL;
}
 /*主函数*/
int main()
{
      int n,b,k;
      LNode *pHead=NULL, *p;//执行初始化操作
    //输入字符的合法性验证暂时忽略
      printf("总猴子数：\n");
      scanf("%d",&n);
      printf("请输入开始报数的猴子编号：\n");
      scanf("%d",&b);
      printf("请输入报数的间隔数：\n");
      scanf("%d",&k);
      p=Create_Linklist(pHead,n);//调用创建链表函数
      Delete_Linklist(p,b,k);//调用删除链表函数
      return 0;
}
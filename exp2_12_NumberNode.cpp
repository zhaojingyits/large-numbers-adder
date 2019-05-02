/************************************************
题目：用单链表实现两个大整数的相加运算(实验2-12)
单位：广西大学 计算机与电子信息学院
作者：计算机类171班 赵敬一
学号：1707310106
所用软件：  Code::Blocks 17.12
            GCC 5.1.0(MinGW32)
            wxWidgets 3.1.1
            wxGlade 0.8.3(Python 3.7)
所用系统：Windows 10
************************************************/

#include "exp2_12_wxMain.h"
#include "exp2_12_NumberNode.h"
/*无参构造*/
NumberNode::NumberNode()
{
    this->next=NULL;
}
/*通过字符串中每一个数字构成的字符构造链表*/
NumberNode::NumberNode(string t)
{
    NumberNode *s;
    wxString ExceptionTemplate=wxT(" is not a decimal number. Please check your input.");
    this->next=NULL;
    for(auto Index:t)/*C++11特性for range循环*/
    {
        if(Index>=48&&Index<=57)/*判断是否有非数字字符*/
        {
            s=new NumberNode();
            s->data=Index-48;
            s->next=this->next;
            this->next=s;
        }
        else if (Index==' '||Index==',')/*处理空格和半角逗号*/
            continue;
        else throw Index+ExceptionTemplate;/*处理其他字符*/
    }
}
/*通过两个链表构造出相加的和*/
NumberNode::NumberNode(NumberNode* p1,NumberNode* p2)
{
    this->next=NULL;
    int temp=0;
    p1=p1->next;
    p2=p2->next;
    NumberNode *s0,*r=this;
    while(p1!=NULL||p2!=NULL||temp!=0)
    {
        if(p1!=NULL)
            temp+=p1->data;
        if(p2!=NULL)
            temp+=p2->data;
        s0=new NumberNode();
        r->next=s0;
        r=s0;
        s0->data=temp%10;
        temp/=10;
        if(p1!=NULL)
            p1=p1->next;
        if(p2!=NULL)
            p2=p2->next;
    }
}
/*析构函数*/
NumberNode::~NumberNode()
{
    delete this->next;
}
/*转换为字符串输出*/
string NumberNode::toString()
{
    string a="";
    char t;
    NumberNode *p=this->next;
    while(p!=NULL)
    {
        t=48+p->data;
        a=t+a;
        p=p->next;
    }
    return a;
}
/*求中值*/
short NumberNode::GetMiddle()
{
    NumberNode *p=this->next,*q=this->next;
    while(q!=NULL&&q->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
    }
    return p->data;
}

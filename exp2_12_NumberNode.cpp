/************************************************
��Ŀ���õ�����ʵ���������������������(ʵ��2-12)
��λ��������ѧ ������������ϢѧԺ
���ߣ��������171�� �Ծ�һ
ѧ�ţ�1707310106
���������  Code::Blocks 17.12
            GCC 5.1.0(MinGW32)
            wxWidgets 3.1.1
            wxGlade 0.8.3(Python 3.7)
����ϵͳ��Windows 10
************************************************/

#include "exp2_12_wxMain.h"
#include "exp2_12_NumberNode.h"
/*�޲ι���*/
NumberNode::NumberNode()
{
    this->next=NULL;
}
/*ͨ���ַ�����ÿһ�����ֹ��ɵ��ַ���������*/
NumberNode::NumberNode(string t)
{
    NumberNode *s;
    wxString ExceptionTemplate=wxT(" is not a decimal number. Please check your input.");
    this->next=NULL;
    for(auto Index:t)/*C++11����for rangeѭ��*/
    {
        if(Index>=48&&Index<=57)/*�ж��Ƿ��з������ַ�*/
        {
            s=new NumberNode();
            s->data=Index-48;
            s->next=this->next;
            this->next=s;
        }
        else if (Index==' '||Index==',')/*����ո�Ͱ�Ƕ���*/
            continue;
        else throw Index+ExceptionTemplate;/*���������ַ�*/
    }
}
/*ͨ���������������ӵĺ�*/
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
/*��������*/
NumberNode::~NumberNode()
{
    delete this->next;
}
/*ת��Ϊ�ַ������*/
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
/*����ֵ*/
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

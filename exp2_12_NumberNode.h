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

#ifndef EXP2_12_NUMBERNODE_H_INCLUDED
#define EXP2_12_NUMBERNODE_H_INCLUDED

/*����wxWidgets�ĵ���������������ʹ��std::stringȻ�������ͼ�ν�����תΪwxString���ʴ˴�ʹ��C++��std::string*/
#include <string>
using std::string;
/*���ݽṹ�Ķ���*/
class NumberNode
{
protected:
	short data;
	NumberNode *next;/*������ָ����һ������ָ��*/

public:
	/*�޲ι���*/
	NumberNode();
	NumberNode(string t);
	NumberNode(NumberNode* p1,NumberNode* p2);
	~NumberNode();
	string toString();
	short GetMiddle();
};


#endif // EXP2_12_NUMBERNODE_H_INCLUDED

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

#ifndef EXP2_12_NUMBERNODE_H_INCLUDED
#define EXP2_12_NUMBERNODE_H_INCLUDED

/*根据wxWidgets文档，建议在运算中使用std::string然后输出到图形界面再转为wxString，故此处使用C++的std::string*/
#include <string>
using std::string;
/*数据结构的定义*/
class NumberNode
{
protected:
	short data;
	NumberNode *next;/*单链表指向下一个结点的指针*/

public:
	/*无参构造*/
	NumberNode();
	NumberNode(string t);
	NumberNode(NumberNode* p1,NumberNode* p2);
	~NumberNode();
	string toString();
	short GetMiddle();
};


#endif // EXP2_12_NUMBERNODE_H_INCLUDED

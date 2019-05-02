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

#ifndef EXP2_12_WXMAIN_H_INCLUDED
#define EXP2_12_WXMAIN_H_INCLUDED

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/notebook.h>

class MainFrame: public wxFrame
{
public:
    MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);

private:
    void set_properties();
    void do_layout();

protected:
    wxTextCtrl* text_ctrl_1;
    wxTextCtrl* text_ctrl_2;
    wxTextCtrl* text_ctrl_disposableresult;
    wxButton* button_disposableadd;
    wxPanel* DisposablePanel;
    wxTextCtrl* text_ctrl_continuousadd;
    wxButton* button_continuousadd;
    wxTextCtrl* text_ctrl_3;
    wxPanel* ContinuousPanel;
    wxPanel* AboutPanel;
    wxNotebook* notebook;
    wxStatusBar* frame_statusbar;

    DECLARE_EVENT_TABLE();

public:
    void disposableadd(wxCommandEvent &event);
    void continuousadd(wxCommandEvent &event);
};

#endif // EXP2_12_WXMAIN_H_INCLUDED

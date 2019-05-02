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
NumberNode *a,*b,*r;
/*定义全局指针*/
/*图形界面的定义*/
MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    SetSize(wxSize(600 , 360));
	/*定义选项卡*/
    notebook = new wxNotebook(this, wxID_ANY);
    AboutPanel = new wxPanel(notebook, wxID_ANY);
    ContinuousPanel = new wxPanel(notebook, wxID_ANY);
    DisposablePanel = new wxPanel(notebook, wxID_ANY);
    frame_statusbar = CreateStatusBar(1);
	/*定义输入框和按钮*/
    text_ctrl_1 = new wxTextCtrl(DisposablePanel, wxID_ANY, wxEmptyString);
    text_ctrl_2 = new wxTextCtrl(DisposablePanel, wxID_ANY, wxEmptyString);
    text_ctrl_disposableresult = new wxTextCtrl(DisposablePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    button_disposableadd = new wxButton(DisposablePanel, 1000, wxT("&Generate Result"));
    text_ctrl_continuousadd = new wxTextCtrl(ContinuousPanel, wxID_ANY, wxEmptyString);
    button_continuousadd = new wxButton(ContinuousPanel, 2000, wxT("&Add"));
    text_ctrl_3 = new wxTextCtrl(ContinuousPanel, wxID_ANY, wxT("0"));

    set_properties();
    do_layout();
}


void MainFrame::set_properties()
{
    /*标题栏*/
    SetTitle(wxT("Large Numbers Adder"));
    /*状态栏*/
    int frame_statusbar_widths[] = { -1 };
    frame_statusbar->SetStatusWidths(1, frame_statusbar_widths);
    const wxString frame_statusbar_fields[] = {
        wxT("Middle Number will be showed here."),
    };
    for(int i = 0; i < frame_statusbar->GetFieldsCount(); ++i) {
        frame_statusbar->SetStatusText(frame_statusbar_fields[i], i);
    }
	/*输入框*/
    text_ctrl_1->SetMinSize(wxSize(130, 25));
    text_ctrl_2->SetMinSize(wxSize(130, 25));
    text_ctrl_disposableresult->SetMinSize(wxSize(130, 25));
    text_ctrl_continuousadd->SetMinSize(wxSize(140, 25));
    text_ctrl_3->SetMinSize(wxSize(150, 25));
}


void MainFrame::do_layout()
{
    /*构建界面*/
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
	/*一次相加界面*/
    wxGridSizer* grid_sizer_1 = new wxGridSizer(0, 1, 0, 0);
    wxGridSizer* grid_sizer_2 = new wxGridSizer(0, 1, 0, 0);
    wxGridSizer* sizer_2 = new wxGridSizer(1, 2, 0, 0);
    wxGridSizer* sizer_3 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer* grid_sizer_3 = new wxGridSizer(0, 7, 0, 0);
    grid_sizer_3->Add(0, 0, 0, 0, 0);
    grid_sizer_3->Add(text_ctrl_1, 0, wxALIGN_CENTER|wxALL, 0);
    wxStaticText* label_plus = new wxStaticText(DisposablePanel, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    grid_sizer_3->Add(label_plus, 0, wxALIGN_CENTER, 0);
    grid_sizer_3->Add(text_ctrl_2, 0, wxALIGN_CENTER, 0);
    wxStaticText* label_equal = new wxStaticText(DisposablePanel, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    grid_sizer_3->Add(label_equal, 0, wxALIGN_CENTER, 0);
    grid_sizer_3->Add(text_ctrl_disposableresult, 0, wxALIGN_CENTER, 0);
    grid_sizer_3->Add(0, 0, 0, 0, 0);
    sizer_3->Add(grid_sizer_3, 1, wxEXPAND, 0);
    sizer_3->Add(button_disposableadd, 0, wxALIGN_CENTER, 0);
    DisposablePanel->SetSizer(sizer_3);
	/*连续相加界面*/
    sizer_2->Add(text_ctrl_continuousadd, 0, wxALIGN_CENTER, 0);
    sizer_2->Add(button_continuousadd, 0, wxALIGN_CENTER, 0);
    grid_sizer_2->Add(sizer_2, 1, wxEXPAND, 0);
    grid_sizer_2->Add(text_ctrl_3, 0, wxALIGN_CENTER, 0);
    ContinuousPanel->SetSizer(grid_sizer_2);
	/*关于界面*/
    wxStaticText* label_1 = new wxStaticText(AboutPanel, wxID_ANY, wxT("Large Numbers Adder"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    label_1->SetFont(wxFont(16, wxROMAN, wxITALIC, wxBOLD, 0, wxT("")));
    grid_sizer_1->Add(label_1, 0, wxALIGN_CENTER, 0);
    wxStaticText* label_2 = new wxStaticText(AboutPanel, wxID_ANY, wxT("By Zhao Jingyi\nGuangxi University\nUsing Code::Blocks 17.12 with GCC 5.1.0 and wxWidgets 3.1.1\nNote: On continuous add page, press Alt+A or click the ""Add"" button\n to add the left number to the below one."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    grid_sizer_1->Add(label_2, 0, wxALIGN_CENTER, 0);
    wxStaticText* label_3 = new wxStaticText(AboutPanel, wxID_ANY, wxT("December 2018"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    grid_sizer_1->Add(label_3, 0, wxALIGN_CENTER, 0);
    AboutPanel->SetSizer(grid_sizer_1);
	/*构建选项卡*/
    notebook->AddPage(DisposablePanel, wxT("Disposable Add"));
    notebook->AddPage(ContinuousPanel, wxT("Continuous Add"));
    notebook->AddPage(AboutPanel, wxT("About This Program"));
    sizer_1->Add(notebook, 1, wxEXPAND, 0);
    SetSizer(sizer_1);
    Layout();
}
/*一次相加按钮的事件处理*/
void MainFrame::disposableadd(wxCommandEvent &event)
{
    if(text_ctrl_1->GetValue()!=wxEmptyString||text_ctrl_2->GetValue()!=wxEmptyString)
    {
        try
        {
            a=new NumberNode(text_ctrl_1->GetValue().ToStdString());
        } catch (wxString &exp)
        {
            wxMessageBox(exp, _T("Error"), wxOK | wxICON_ERROR);
            delete a;
            delete b;
            return;
        }
        try
        {
            b=new NumberNode(text_ctrl_2->GetValue().ToStdString());
        } catch (wxString &exp)
        {
            wxMessageBox(exp, _T("Error"), wxOK | wxICON_ERROR);
            delete a;
            delete b;
            return;
        }
        r=new NumberNode(a,b);
        wxString ResultStr(r->toString());/*输出需要将std::string转换为wxString类型*/
        text_ctrl_disposableresult->SetValue(ResultStr);/*在结果框中写入相应结果*/
        frame_statusbar->SetStatusText(wxT("Middle Number: ")+ wxString::Format(wxT("%i"),r->GetMiddle()), 0);/*在状态栏输出中值*/
        delete a;
        delete b;
        delete r;
    }
    event.Skip();
}
/*连续相加按钮的事件处理*/
void MainFrame::continuousadd(wxCommandEvent &event)
{
    if(text_ctrl_continuousadd->GetValue()!=wxEmptyString)
    {
        try
        {
            a=new NumberNode(text_ctrl_continuousadd->GetValue().ToStdString());
        } catch (wxString &exp)
        {
            wxMessageBox(exp, _T("Error"), wxOK | wxICON_ERROR);
            delete a;
            delete b;
            return;
        }
        try
        {
            b=new NumberNode(text_ctrl_3->GetValue().ToStdString());
        } catch (wxString &exp)
        {
            wxMessageBox(exp, _T("Error"), wxOK | wxICON_ERROR);
            delete a;
            delete b;
            return;
        }
        r=new NumberNode(a,b);
        wxString ResultStr(r->toString());
        text_ctrl_3->SetValue(ResultStr);
        frame_statusbar->SetStatusText(wxT("Middle Number: ")+ wxString::Format(wxT("%i"),r->GetMiddle()), 0);
        delete a;
        delete b;
        delete r;
    }
    event.Skip();
}

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    /*关联事件处理函数*/
    EVT_BUTTON(1000, MainFrame::disposableadd)
    EVT_BUTTON(2000, MainFrame::continuousadd)
END_EVENT_TABLE();

class MyApp: public wxApp
{
public:
    bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MainFrame* frame = new MainFrame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(frame);
    frame->Show();
    return true;
}

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

#ifndef FORMDIALOG_HPP
#define FORMDIALOG_HPP

#include <wx/wx.h>
#include <string>

class FormDialog : public wxDialog
{
public:
    FormDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);

    std::string GetNameValue() const;
    std::string GetLengthValue() const;
    std::string GetTypeValue() const;

private:

    wxTextCtrl* nameCtrl;
    wxTextCtrl* lengthCtrl;
    wxTextCtrl* typeCtrl;

};

class ConfirmFormDialog : public wxDialog
{
public:
    ConfirmFormDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);

};


#endif // !FORMDIALOG_HPP

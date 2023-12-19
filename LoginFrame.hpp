#ifndef LOGINFRAME_HPP
#define LOGINFRAME_HPP

#include <wx/wx.h>

class LoginFrame : public wxFrame
{
public:
	wxPanel* m_parent;

	LoginFrame(const wxString& title);
	void OnLogin(wxCommandEvent& event);
	void OnClose(wxCloseEvent& event);
private:
	wxTextCtrl* usernameTextCtrl;
	wxTextCtrl* passwordTextCtrl;
	wxButton* loginButton;
};

#endif // !LOGINFRAME_HPP

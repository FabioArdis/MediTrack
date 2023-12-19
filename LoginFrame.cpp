#include "LoginFrame.hpp"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include "bcrypt.h"
#include "UserDAO.hpp"
#include "MediTrack.h"

LoginFrame::LoginFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{
	Bind(wxEVT_CLOSE_WINDOW, &LoginFrame::OnClose, this);

	m_parent = new wxPanel(this, wxID_ANY);

	wxBoxSizer* vBox = new wxBoxSizer(wxVERTICAL);

	wxStaticText* usernameLabel = new wxStaticText(m_parent, wxID_ANY, wxT("Username"));
	usernameTextCtrl = new wxTextCtrl(m_parent, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);

	wxStaticText* passwordLabel = new wxStaticText(m_parent, wxID_ANY, wxT("Password"));
	passwordTextCtrl = new wxTextCtrl(m_parent, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

	loginButton = new wxButton(m_parent, wxID_ANY, "Login");
	loginButton->Bind(wxEVT_BUTTON, &LoginFrame::OnLogin, this);

	vBox->Add(usernameLabel, 0, wxEXPAND | wxALL, 5);
	vBox->Add(usernameTextCtrl, 0, wxEXPAND | wxALL, 5);
	vBox->Add(passwordLabel, 0, wxEXPAND | wxALL, 5);
	vBox->Add(passwordTextCtrl, 0, wxEXPAND | wxALL, 5);
	vBox->Add(loginButton, 0, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(vBox);

	this->Centre();
}

void LoginFrame::OnLogin(wxCommandEvent& event)
{
	wxString username = this->usernameTextCtrl->GetValue();
	wxString password = this->passwordTextCtrl->GetValue();

	bool check = (UserDAO::getInstance()->authUser(username.ToStdString(), password.ToStdString()));

	if (check)
	{
		loggedIn = true;
		wxCommandEvent newEvent(LOGIN_SUCCESS_EVENT);
		wxPostEvent(wxTheApp, newEvent);
		this->Close();
	}
	else
		wxMessageBox(wxT("Email o password sbagliata. Riprova"));
}

void LoginFrame::OnClose(wxCloseEvent& event)
{
	if (loggedIn)
		this->Destroy();
	else
	{
		wxTheApp->Exit();
		event.Skip();
	}
}

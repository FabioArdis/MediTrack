#include "MediTrack.h"
#include <wx/wx.h>

wxDEFINE_EVENT(LOGIN_SUCCESS_EVENT, wxCommandEvent);

wxIMPLEMENT_APP(MediTrack);

bool MediTrack::OnInit()
{
	/*
	* Implementare il login prima di far partire il mainFrame.
	*/
	loginFrame = new LoginFrame(wxT("Login"));
	mainFrame = new MainFrame(wxT("MediTrack"));

	loginFrame->Show(true);
	//mainFrame->Show(true);

	Bind(LOGIN_SUCCESS_EVENT, &MediTrack::OnLoginSuccess, this);

	return true;
}

void MediTrack::OnLoginSuccess(wxCommandEvent& event)
{
	mainFrame->Show();
}
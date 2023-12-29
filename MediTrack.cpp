#include "MediTrack.h"
#include <wx/wx.h>

wxDEFINE_EVENT(LOGIN_SUCCESS_EVENT, wxCommandEvent);

wxIMPLEMENT_APP(MediTrack);

bool MediTrack::OnInit()
{
	loginFrame = new LoginFrame(wxT("Login"));
	mainFrame = new MainFrame(wxT("MediTrack"));

	loginFrame->Show(true);

	Bind(LOGIN_SUCCESS_EVENT, &MediTrack::OnLoginSuccess, this);

	return true;
}

void MediTrack::OnLoginSuccess(wxCommandEvent& event)
{
	mainFrame->Show();
}
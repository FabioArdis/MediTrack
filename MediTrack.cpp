#include "MediTrack.h"
#include "MainFrame.h"
#include "LoginFrame.hpp"
#include <wx/wx.h>

wxIMPLEMENT_APP(MediTrack);

bool MediTrack::OnInit()
{
	/*
	* Implementare il login prima di far partire il mainFrame.
	*/
	LoginFrame* loginFrame = new LoginFrame(wxT("Login"));
	MainFrame* mainFrame = new MainFrame(wxT("MediTrack"));

	loginFrame->Show(true);
	mainFrame->Show(true);

	return true;
}
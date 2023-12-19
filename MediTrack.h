#ifndef MEDITRACK_HPP
#define MEDITRACK_HPP

#include <wx/wx.h>
#include "MainFrame.h"
#include "LoginFrame.hpp"

wxDECLARE_EVENT(LOGIN_SUCCESS_EVENT, wxCommandEvent);

class MediTrack : public wxApp
{
public:
	MainFrame* mainFrame;
	LoginFrame* loginFrame;

	bool OnInit();
	void OnLoginSuccess(wxCommandEvent& event);
};

#endif // !MEDITRACK_HPP


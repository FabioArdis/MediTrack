#include "LoginFrame.hpp"
#include "bcrypt.h"

LoginFrame::LoginFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
	m_parent = new wxPanel(this, wxID_ANY);

	this->Centre();
}
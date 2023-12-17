#ifndef LOGINFRAME_HPP
#define LOGINFRAME_HPP

#include <wx/wx.h>

class LoginFrame : public wxFrame
{
public:
	LoginFrame(const wxString& title);

	wxPanel* m_parent;
};

#endif // !LOGINFRAME_HPP

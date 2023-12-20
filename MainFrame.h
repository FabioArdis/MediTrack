#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wx.h>
#include "User.hpp"
#include "UserDAO.hpp"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	wxPanel* m_parent;

	User* m_user = UserDAO::getInstance()->getUser();

};
#endif // !MAINFRAME_HPP


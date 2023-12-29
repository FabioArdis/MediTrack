#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wx.h>
#include "PlanFrame.hpp"
#include "User.hpp"
#include "UserDAO.hpp"
#include "Mediator.hpp"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	wxPanel* m_parent;
	PlanFrame* m_planFrame;
	wxListBox* plansList;

	User* m_user = UserDAO::getInstance()->getUser();
	PlanUpdater* m_mediator;

	void onAdd(wxCommandEvent& event);
	void onEdit(wxCommandEvent& event);

private:
	std::vector<Plan>* m_plans;

	wxButton* addButton;
	wxButton* editButton;
	wxButton* syncButton;
};
#endif // !MAINFRAME_HPP


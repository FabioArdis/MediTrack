#ifndef PLANFRAME_HPP
#define PLANFRAME_HPP

#include <wx/wx.h>
#include "Plan.hpp"
#include "Mediator.hpp"

class PlanFrame : public wxFrame
{
public:
	PlanFrame(const wxString& title, Plan& plan, PlanUpdater* mediator);

	wxPanel* m_parent;

	PlanUpdater* m_mediator;

	Plan& m_plan;

	wxListBox* medsList;

	wxTextCtrl* planNameCtrl;
	wxTextCtrl* medNameCtrl;
	wxTextCtrl* medDosageCtrl;
	wxTextCtrl* medManuCtrl;
	wxTextCtrl* medBatchCtrl;
	wxTextCtrl* medExpCtrl;
	wxTextCtrl* medNotesCtrl;

	void OnListBoxSelection(wxCommandEvent& event);
	void OnClickAddMed(wxCommandEvent& event);

private:
	wxButton* addMedBtn;
	wxButton* updatePlanBtn;
};

#endif // !PLANFRAME_HPP

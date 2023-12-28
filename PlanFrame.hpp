#ifndef PLANFRAME_HPP
#define PLANFRAME_HPP

#include <wx/wx.h>
#include "Plan.hpp"
#include "Mediator.hpp"

class PlanFrame : public wxFrame
{
public:
	PlanFrame(wxFrame* parent, const wxString& title, Plan& plan, PlanUpdater* mediator);

	wxPanel* m_parent;

	PlanUpdater* m_mediator;

	Plan& m_plan;

	wxListBox* medsList;

	wxTextCtrl* planNameCtrl;
	wxTextCtrl* planLengthCtrl;
	wxTextCtrl* planTypeCtrl;

	wxTextCtrl* medNameCtrl;
	wxTextCtrl* medDosageCtrl;
	wxTextCtrl* medManuCtrl;
	wxTextCtrl* medBatchCtrl;
	wxTextCtrl* medExpCtrl;
	wxTextCtrl* medNotesCtrl;

	void OnListBoxSelection(wxCommandEvent& event);
	void OnClickAddMed(wxCommandEvent& event);
	void OnClickUpdPlan(wxCommandEvent& event);
	void OnClickUpdMed(wxCommandEvent& event);

private:
	wxButton* addMedBtn;
	wxButton* updatePlanBtn;
	wxButton* updateMedBtn;
};

#endif // !PLANFRAME_HPP

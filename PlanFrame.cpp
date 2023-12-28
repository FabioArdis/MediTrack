#include <wx/wx.h>
#include <wx/statline.h>
#include "PlanFrame.hpp"

PlanFrame::PlanFrame(wxFrame* parent, const wxString& title, Plan& plan, PlanUpdater* mediator) : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxSize(600, 700)), m_plan(plan), m_mediator(mediator)
{
	this->SetMinSize(wxSize(600, 700));
	this->SetMaxSize(wxSize(600, 700));

	m_parent = new wxPanel(this, wxID_ANY);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* medicineSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* infoSizer = new wxBoxSizer(wxVERTICAL);

	wxArrayString a_medsName;

	for (auto i : m_plan.getMeds())
		a_medsName.Add(i->getInfo(MedInfo::NAME));

	planNameCtrl = new wxTextCtrl(m_parent, wxID_ANY, m_plan.getName(), wxPoint(50, 50));
	planLengthCtrl = new wxTextCtrl(m_parent, wxID_ANY, m_plan.getLength(), wxPoint(50, 50));
	planTypeCtrl = new wxTextCtrl(m_parent, wxID_ANY, m_plan.getType(), wxPoint(50, 50));

	medNameCtrl = new wxTextCtrl(m_parent, wxID_ANY, "Nome", wxPoint(50, 50));
	medDosageCtrl = new wxTextCtrl(m_parent, wxID_ANY, "Dosage", wxPoint(50, 50));
	medManuCtrl = new wxTextCtrl(m_parent, wxID_ANY, "Manufacturer", wxPoint(50, 50));
	medBatchCtrl = new wxTextCtrl(m_parent, wxID_ANY, "Batch number", wxPoint(50, 50));
	medExpCtrl = new wxTextCtrl(m_parent, wxID_ANY, "Expiration time", wxPoint(50, 50));
	medNotesCtrl = new wxTextCtrl(m_parent, wxID_ANY, "Aggiungi delle note...", wxPoint(50, 50), wxDefaultSize, wxTE_MULTILINE);

	medsList = new wxListBox(m_parent, wxID_ANY, wxPoint(50, 50), wxSize(100, -1), a_medsName);

	medsList->Bind(wxEVT_LISTBOX, &PlanFrame::OnListBoxSelection, this);

	addMedBtn = new wxButton(m_parent, wxID_ANY, "Aggiungi medicinale", wxPoint(50, 100));
	updatePlanBtn = new wxButton(m_parent, wxID_ANY, "Aggiorna il piano ed esci", wxPoint(50, 100));

	addMedBtn->Bind(wxEVT_BUTTON, &PlanFrame::OnClickAddMed, this);
	updatePlanBtn->Bind(wxEVT_BUTTON, &PlanFrame::OnClickUpdPlan, this);
	
	updateMedBtn = new wxButton(m_parent, wxID_ANY, "Aggiorna farmaco", wxPoint(50, 100));

	mainSizer->Add(medicineSizer, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(new wxStaticLine(m_parent, wxID_ANY, wxPoint(25, 50), wxSize(1, 300)), 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(infoSizer, 1, wxEXPAND | wxALL, 5);

	medicineSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Nome piano terapeutico", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(planNameCtrl, 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Lunghezza piano terapeutico", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(planLengthCtrl, 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Tipo piano terapeutico", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(planTypeCtrl, 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(new wxStaticLine(m_parent, wxID_ANY, wxPoint(25, 50), wxSize(300, 1)), 0, wxEXPAND | wxALL, 5);

	medicineSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Farmaci", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(medsList, 1, wxEXPAND | wxALL, 5);
	medicineSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 5);

	buttonSizer->Add(addMedBtn, 1, wxEXPAND | wxALL, 5);
	buttonSizer->Add(updatePlanBtn, 1, wxEXPAND | wxALL, 5);

	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Cerca farmaco", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Nome farmaco", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxButton(m_parent, wxID_ANY, "Cerca", wxPoint(50, 100)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticLine(m_parent, wxID_ANY, wxPoint(25, 50), wxSize(300, 1)), 0, wxEXPAND | wxALL, 5);

	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Compila farmaco", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Nome", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(medNameCtrl, 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Dosage", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(medDosageCtrl, 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Manufacturer", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(medManuCtrl, 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Batch number", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(medBatchCtrl, 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Expiration time", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(medExpCtrl, 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Note", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(medNotesCtrl, 1, wxEXPAND | wxALL, 5);
	infoSizer->Add(updateMedBtn, 0, wxEXPAND | wxALL, 5);

	updateMedBtn->Bind(wxEVT_BUTTON, &PlanFrame::OnClickUpdMed, this);

	m_parent->SetSizer(mainSizer);

	this->Centre();


}

void PlanFrame::OnListBoxSelection(wxCommandEvent& event)
{
	m_mediator->update(this);
}

void PlanFrame::OnClickAddMed(wxCommandEvent& event)
{
	Medicine* testMedicine = new Medicine();
	m_plan.addMed(testMedicine);
	m_mediator->update(this);
}

void PlanFrame::OnClickUpdPlan(wxCommandEvent& event)
{
	m_plan.setName(planNameCtrl->GetValue().ToStdString());
	m_plan.setLength(planLengthCtrl->GetValue().ToStdString());
	m_plan.setType(planTypeCtrl->GetValue().ToStdString());
	m_mediator->update();
	this->Hide();
}

void PlanFrame::OnClickUpdMed(wxCommandEvent& event)
{
	for (auto& i : m_plan.getMeds())
	{
		if (i->getInfo(MedInfo::NAME) == medsList->GetStringSelection())
		{
			try
			{
				i->setInfo(MedInfo::NAME, medNameCtrl->GetValue().ToStdString());
				i->setInfo(MedInfo::DSGE, medDosageCtrl->GetValue().ToStdString());
				i->setInfo(MedInfo::MNFC, medManuCtrl->GetValue().ToStdString());
				i->setInfo(MedInfo::BTNO, medBatchCtrl->GetValue().ToStdString());
				i->setInfo(MedInfo::EXPT, medExpCtrl->GetValue().ToStdString());
				i->setInfo(MedInfo::NOTE, medNotesCtrl->GetValue().ToStdString());
			}
			catch (const std::exception& e)
			{
				MessageBoxA(NULL, e.what(), "Exception Caught:", MB_OK);
			}
		}
	}

	m_mediator->update(this);
}

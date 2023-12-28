#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include "MainFrame.h"


MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
	this->SetMinSize(wxSize(500, 300));
	this->SetMaxSize(wxSize(500, 300));
	m_parent = new wxPanel(this, wxID_ANY);

	m_plans = &m_user->plans;
	wxArrayString a_plansName;

	m_mediator = new PlanUpdater(this, m_planFrame);

	for (auto i = m_plans->begin(); i != m_plans->end(); i++)
		a_plansName.Add(i->getName());

	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* plansSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* doctorsSizer = new wxBoxSizer(wxVERTICAL);

	addButton = new wxButton(m_parent, wxID_ANY, "Aggiungi", wxPoint(50, 100));
	editButton = new wxButton(m_parent, wxID_ANY, "Modifica", wxPoint(50, 100));
	syncButton = new wxButton(m_parent, wxID_ANY, "Sincronizza", wxPoint(50, 100));
	plansList = new wxListBox(m_parent, wxID_ANY, wxPoint(50, 50), wxSize(100, -1), a_plansName);

	addButton->Bind(wxEVT_BUTTON, &MainFrame::onAdd, this);
	editButton->Bind(wxEVT_BUTTON, &MainFrame::onEdit, this);

	wxArrayString doctors;
	doctors.Add("Dottore1 - Specializzazione1");
	doctors.Add("Dottore2 - Specializzazione2");
	doctors.Add("Dottore3 - Specializzazione3");

	std::string prova = "password";

	mainSizer->Add(plansSizer, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(new wxStaticLine(m_parent, wxID_ANY, wxPoint(25, 50), wxSize(1, 300)), 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(doctorsSizer, 1, wxEXPAND | wxALL, 5);

	plansSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Benvenuto, " + m_user->getFullName() + ".", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	plansSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Piani terapeutici", wxPoint(50, 50), wxDefaultSize, wxALIGN_CENTER), 0, wxEXPAND | wxALL, 5);
	plansSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Cerca piano", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	plansSizer->Add(new wxButton(m_parent, wxID_ANY, "Cerca", wxPoint(50, 100)), 0, wxEXPAND | wxALL, 5);
	plansSizer->Add(plansList, 1, wxEXPAND | wxALL, 5);
	plansSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 5);

	buttonSizer->Add(addButton, 1, wxEXPAND | wxALL, 5);
	buttonSizer->Add(editButton, 1, wxEXPAND | wxALL, 5);
	buttonSizer->Add(syncButton, 1, wxEXPAND | wxALL, 5);

	doctorsSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Dottori", wxPoint(50, 50), wxDefaultSize, wxALIGN_CENTER), 0, wxEXPAND | wxALL, 5);
	doctorsSizer->Add(new wxListBox(m_parent, wxID_ANY, wxPoint(50, 50), wxSize(100, -1), doctors), 1, wxEXPAND | wxALL, 5);
	doctorsSizer->Add(new wxButton(m_parent, wxID_ANY, "Contatta", wxPoint(50, 100)), 0, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(mainSizer);

	this->Centre();
}

void MainFrame::onAdd(wxCommandEvent& event)
{
	Plan newPlan("Nuovo Piano" + std::to_string(m_plans->size()));
	m_plans->push_back(newPlan);
	m_mediator->updateListBox(newPlan.getName());
}

void MainFrame::onEdit(wxCommandEvent& event)
{
	int index = plansList->GetSelection();
	for (auto i = m_plans->begin(); i != m_plans->end(); i++)
	{
		if (i->getName() == plansList->GetString(index))
		{
			m_planFrame = new PlanFrame(wxT("Aggiungi o modifica piano"), *i, m_mediator);
			m_planFrame->Show(true);
		}
	}
}

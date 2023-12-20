#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include "MainFrame.h"


MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
	m_parent = new wxPanel(this, wxID_ANY);
	Medicine testMedicine;
	std::vector<Medicine> testVectorMedicines;
	testVectorMedicines.push_back(testMedicine);
	Plan testPlan("TestPlan", testVectorMedicines);
	m_user->addPlan(testPlan);

	std::vector<Plan> m_plans = m_user->getPlans();
	wxArrayString a_plansName;

	for (auto i : m_plans)
		a_plansName.Add(i.getName());



	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* plansSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* doctorsSizer = new wxBoxSizer(wxVERTICAL);

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
	plansSizer->Add(new wxListBox(m_parent, wxID_ANY, wxPoint(50, 50), wxSize(100, -1), a_plansName), 1, wxEXPAND | wxALL, 5);
	plansSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 5);
	buttonSizer->Add(new wxButton(m_parent, wxID_ANY, "Aggiungi", wxPoint(50, 100)), 1, wxEXPAND | wxALL, 5);
	buttonSizer->Add(new wxButton(m_parent, wxID_ANY, "Sincronizza", wxPoint(50, 100)), 1, wxEXPAND | wxALL, 5);

	doctorsSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Dottori", wxPoint(50, 50), wxDefaultSize, wxALIGN_CENTER), 0, wxEXPAND | wxALL, 5);
	doctorsSizer->Add(new wxListBox(m_parent, wxID_ANY, wxPoint(50, 50), wxSize(100, -1), doctors), 1, wxEXPAND | wxALL, 5);
	doctorsSizer->Add(new wxButton(m_parent, wxID_ANY, "Contatta", wxPoint(50, 100)), 0, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(mainSizer);

	this->Centre();
}
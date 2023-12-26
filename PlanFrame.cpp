#include <wx/wx.h>
#include <wx/statline.h>
#include "PlanFrame.hpp"

PlanFrame::PlanFrame(const wxString& title, Plan& plan) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 700)), m_plan(plan)
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
		a_medsName.Add(i.getInfo("name"));

	mainSizer->Add(medicineSizer, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(new wxStaticLine(m_parent, wxID_ANY, wxPoint(25, 50), wxSize(1, 300)), 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(infoSizer, 1, wxEXPAND | wxALL, 5);

	medicineSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Nome piano terapeutico", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, m_plan.getName(), wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(new wxStaticLine(m_parent, wxID_ANY, wxPoint(25, 50), wxSize(300, 1)), 0, wxEXPAND | wxALL, 5);

	medicineSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Farmaci", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	medicineSizer->Add(new wxListBox(m_parent, wxID_ANY, wxPoint(50, 50), wxSize(100, -1), a_medsName), 1, wxEXPAND | wxALL, 5);
	medicineSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 5);

	buttonSizer->Add(new wxButton(m_parent, wxID_ANY, "Aggungi", wxPoint(50, 100)), 1, wxEXPAND | wxALL, 5);
	buttonSizer->Add(new wxButton(m_parent, wxID_ANY, "Esci e aggiorna piano", wxPoint(50, 100)), 1, wxEXPAND | wxALL, 5);

	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Cerca farmaco", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Nome farmaco", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxButton(m_parent, wxID_ANY, "Cerca", wxPoint(50, 100)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticLine(m_parent, wxID_ANY, wxPoint(25, 50), wxSize(300, 1)), 0, wxEXPAND | wxALL, 5);

	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Compila farmaco", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Nome", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Nome", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Dosage", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Dosage", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Manufacturer", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Manufacturer", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Batch number", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Batch number", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Expiration time", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Expiration time", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxStaticText(m_parent, wxID_ANY, "Note", wxPoint(50, 50)), 0, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxTextCtrl(m_parent, wxID_ANY, "Aggiungi delle note...", wxPoint(50, 50)), 1, wxEXPAND | wxALL, 5);
	infoSizer->Add(new wxButton(m_parent, wxID_ANY, "Aggiorna farmaco", wxPoint(50, 100)), 0, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(mainSizer);

	this->Centre();


}

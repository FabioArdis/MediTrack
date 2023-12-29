#include "FormDialog.hpp"

FormDialog::FormDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, wxSize(250, 275), style)
{
    this->SetMinSize(wxSize(250, 275));
    this->SetMaxSize(wxSize(250, 275));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    nameCtrl = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);
    lengthCtrl = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);
    typeCtrl = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);

    mainSizer->Add(new wxStaticText(this, wxID_ANY, wxT("Nome:")), 0, wxALL, 5);
    mainSizer->Add(nameCtrl, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(new wxStaticText(this, wxID_ANY, wxT("Durata:")), 0, wxALL, 5);
    mainSizer->Add(lengthCtrl, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(new wxStaticText(this, wxID_ANY, wxT("Tipo:")), 0, wxALL, 5);
    mainSizer->Add(typeCtrl, 0, wxEXPAND | wxALL, 5);

    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 5);

    buttonSizer->Add(new wxButton(this, wxID_OK, wxT("Continua")), 1, wxALL, 5);
    buttonSizer->Add(new wxButton(this, wxID_CANCEL, wxT("Annulla")), 1, wxALL, 5);

    SetSizer(mainSizer);

    Centre();
}

std::string FormDialog::GetNameValue() const
{
    return nameCtrl->GetValue().ToStdString();
}

std::string FormDialog::GetLengthValue() const
{
    return lengthCtrl->GetValue().ToStdString();
}

std::string FormDialog::GetTypeValue() const
{
    return typeCtrl->GetValue().ToStdString();
}

ConfirmFormDialog::ConfirmFormDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, wxSize(250, 275), style)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* messageText = new wxStaticText(this, wxID_ANY, 
        "Do you want to continue in the plan creation?", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    sizer->Add(messageText, 0, wxALL | wxEXPAND, 10);

    wxStdDialogButtonSizer* buttonSizer = CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    sizer->Add(buttonSizer, 0, wxALL | wxALIGN_CENTER, 10);

    SetSizerAndFit(sizer);
}

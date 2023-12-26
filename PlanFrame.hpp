#ifndef PLANFRAME_HPP
#define PLANFRAME_HPP

#include <wx/wx.h>
#include "Plan.hpp"
<<<<<<< HEAD
#include "Mediator.hpp"
=======
>>>>>>> ca6e164 (Il file MainFrame.cpp è stato aggiornatoper utilizzare un oggetto Plan senza inizializzarlo con un vettore di Medicine. È stato aggiunto un PlanUpdater, nuovi pulsanti e una casella di lista al frame. È stata aggiunta una connessione agli eventi per il pulsante "addButton" con un nuovo metodo onAdd in MainFrame.cpp. Sono stati aggiunti al progetto i file PlanFrame.cpp, Mediator.cpp, PlanFrame.hpp e Mediator.hpp. È stato aggiunto un costruttore predefinito alla classe Plan in Plan.cpp e Plan.hpp. Sono state aggiunte nuove classi Mediator e PlanUpdater in Mediator.cpp e Mediator.hpp. Infine, è stata aggiunta una nuova classe PlanFrame in PlanFrame.cpp e PlanFrame.hpp.)

class PlanFrame : public wxFrame
{
public:
<<<<<<< HEAD
	PlanFrame(const wxString& title, Plan& plan, PlanUpdater* mediator);

	wxPanel* m_parent;

	PlanUpdater* m_mediator;

	Plan m_plan;

	wxListBox* medsList;

	wxTextCtrl* planNameCtrl;
	wxTextCtrl* medNameCtrl;
	wxTextCtrl* medDosageCtrl;
	wxTextCtrl* medManuCtrl;
	wxTextCtrl* medBatchCtrl;
	wxTextCtrl* medExpCtrl;
	wxTextCtrl* medNotesCtrl;

	void OnListBoxSelection(wxCommandEvent& event);
=======
	PlanFrame(const wxString& title, Plan& plan);

	wxPanel* m_parent;

	Plan m_plan;
>>>>>>> ca6e164 (Il file MainFrame.cpp è stato aggiornatoper utilizzare un oggetto Plan senza inizializzarlo con un vettore di Medicine. È stato aggiunto un PlanUpdater, nuovi pulsanti e una casella di lista al frame. È stata aggiunta una connessione agli eventi per il pulsante "addButton" con un nuovo metodo onAdd in MainFrame.cpp. Sono stati aggiunti al progetto i file PlanFrame.cpp, Mediator.cpp, PlanFrame.hpp e Mediator.hpp. È stato aggiunto un costruttore predefinito alla classe Plan in Plan.cpp e Plan.hpp. Sono state aggiunte nuove classi Mediator e PlanUpdater in Mediator.cpp e Mediator.hpp. Infine, è stata aggiunta una nuova classe PlanFrame in PlanFrame.cpp e PlanFrame.hpp.)
};

#endif // !PLANFRAME_HPP

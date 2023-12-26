#include "Mediator.hpp"
#include "MainFrame.h"

void PlanUpdater::update()
{
}

<<<<<<< HEAD
void PlanUpdater::update(MainFrame* mF)
{
}

void PlanUpdater::update(PlanFrame* pF)
{
	m_pF = pF;
	int index = m_pF->medsList->GetSelection();
	for (auto i : m_pF->m_plan.getMeds())
	{
		if (i.getInfo("name") == m_pF->medsList->GetString(index))
		{
			m_pF->medNameCtrl->SetValue(i.getInfo("name"));
			m_pF->medDosageCtrl->SetValue(i.getInfo("dosage"));
			m_pF->medManuCtrl->SetValue(i.getInfo("manufacturer"));
			m_pF->medBatchCtrl->SetValue(i.getInfo("batchNo"));
			m_pF->medExpCtrl->SetValue(i.getInfo("expirationTime"));
		}
	}
}

void PlanUpdater::updateAll()
{
}

void PlanUpdater::updateListBox(const wxString& str)
{
	m_mF->plansList->Append(str);
=======
void PlanUpdater::updateListBox(const wxString& str)
{
	m_mf->plansList->Append(str);
>>>>>>> ca6e164 (Il file MainFrame.cpp è stato aggiornatoper utilizzare un oggetto Plan senza inizializzarlo con un vettore di Medicine. È stato aggiunto un PlanUpdater, nuovi pulsanti e una casella di lista al frame. È stata aggiunta una connessione agli eventi per il pulsante "addButton" con un nuovo metodo onAdd in MainFrame.cpp. Sono stati aggiunti al progetto i file PlanFrame.cpp, Mediator.cpp, PlanFrame.hpp e Mediator.hpp. È stato aggiunto un costruttore predefinito alla classe Plan in Plan.cpp e Plan.hpp. Sono state aggiunte nuove classi Mediator e PlanUpdater in Mediator.cpp e Mediator.hpp. Infine, è stata aggiunta una nuova classe PlanFrame in PlanFrame.cpp e PlanFrame.hpp.)
}

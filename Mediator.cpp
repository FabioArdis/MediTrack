#include "Mediator.hpp"
#include "MainFrame.h"

void PlanUpdater::update()
{
}

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
}

#include "Mediator.hpp"
#include "MainFrame.h"

void PlanUpdater::update()
{
	if(m_mF)
		update(m_mF);
	if (m_pF)
		update(m_pF);
}

void PlanUpdater::update(MainFrame* mF)
{
	m_mF = mF;
	
	m_mF->plansList->Clear();

	for (auto& i : m_mF->m_user->plans)
		m_mF->plansList->Append(i.getName());
}

void PlanUpdater::update(PlanFrame* pF)
{
	m_pF = pF;
	int index;

	if (m_pF->medsList->IsEmpty())
		index = 0;
	else
		index = m_pF->medsList->GetSelection();
	m_pF->medsList->Clear();

	for (auto i : m_pF->m_plan.getMeds())
	{
		m_pF->medsList->Append(i.getInfo("name"));
	}

	m_pF->medsList->SetSelection(index);
	if (!m_pF->medsList->IsEmpty())
	{
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
}

void PlanUpdater::updateAll()
{
}

void PlanUpdater::updateListBox(const wxString& str)
{
	/*m_mF->plansList->Clear();
	m_mF->plansList->Append(str);*/
}

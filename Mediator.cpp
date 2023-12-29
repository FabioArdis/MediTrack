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

	int index;

	if (m_mF->plansList->IsEmpty())
		index = 0;
	else
		index = m_mF->plansList->GetSelection();

	m_mF->plansList->Clear();

	for (auto& i : m_mF->m_user->plans)
		m_mF->plansList->Append(i.getName());

	m_mF->plansList->SetSelection(index);
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
		m_pF->medsList->Append(i->getInfo(MedInfo::NAME));
	}

	m_pF->medsList->SetSelection(index);

	if (!m_pF->medsList->IsEmpty())
	{
		for (auto i : m_pF->m_plan.getMeds())
		{
			if (i->getInfo(MedInfo::NAME) == m_pF->medsList->GetString(index))
			{
				m_pF->medNameCtrl->SetValue(i->getInfo(MedInfo::NAME));
				m_pF->medDosageCtrl->SetValue(i->getInfo(MedInfo::DSGE));
				m_pF->medManuCtrl->SetValue(i->getInfo(MedInfo::MNFC));
				m_pF->medBatchCtrl->SetValue(i->getInfo(MedInfo::BTNO));
				m_pF->medExpCtrl->SetValue(i->getInfo(MedInfo::EXPT));
				m_pF->medNotesCtrl->SetValue(i->getInfo(MedInfo::NOTE));
			}
		}
	}
}

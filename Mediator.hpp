#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include <wx/wx.h>

// Forward Declaration
class MainFrame;
class PlanFrame;

class Mediator
{
public:
	virtual void update() = 0;
};

class PlanUpdater : public Mediator
{
private:
	MainFrame* m_mF;
	PlanFrame* m_pF;
public:
	PlanUpdater(MainFrame* mF, PlanFrame* pF) : m_mF(mF), m_pF(pF) {}
	void update() override;
	void update(MainFrame* mF);
	void update(PlanFrame* pF);
};

#endif // !MEDIATOR_HPP

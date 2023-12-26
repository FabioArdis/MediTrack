#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include <wx/wx.h>

// Forward Declaration
class MainFrame;
<<<<<<< HEAD
class PlanFrame;
=======
>>>>>>> ca6e164 (Il file MainFrame.cpp è stato aggiornatoper utilizzare un oggetto Plan senza inizializzarlo con un vettore di Medicine. È stato aggiunto un PlanUpdater, nuovi pulsanti e una casella di lista al frame. È stata aggiunta una connessione agli eventi per il pulsante "addButton" con un nuovo metodo onAdd in MainFrame.cpp. Sono stati aggiunti al progetto i file PlanFrame.cpp, Mediator.cpp, PlanFrame.hpp e Mediator.hpp. È stato aggiunto un costruttore predefinito alla classe Plan in Plan.cpp e Plan.hpp. Sono state aggiunte nuove classi Mediator e PlanUpdater in Mediator.cpp e Mediator.hpp. Infine, è stata aggiunta una nuova classe PlanFrame in PlanFrame.cpp e PlanFrame.hpp.)

class Mediator
{
public:
	virtual void update() = 0;
};

class PlanUpdater : public Mediator
{
private:
<<<<<<< HEAD
	MainFrame* m_mF;
	PlanFrame* m_pF;
public:
	PlanUpdater(MainFrame* mF, PlanFrame* pF) : m_mF(mF), m_pF(pF) {}
	void update() override;
	void update(MainFrame* mF);
	void update(PlanFrame* pF);
	void updateAll();
=======
	MainFrame* m_mf;
public:
	PlanUpdater(MainFrame* mf) : m_mf(mf) {}
	void update() override;
>>>>>>> ca6e164 (Il file MainFrame.cpp è stato aggiornatoper utilizzare un oggetto Plan senza inizializzarlo con un vettore di Medicine. È stato aggiunto un PlanUpdater, nuovi pulsanti e una casella di lista al frame. È stata aggiunta una connessione agli eventi per il pulsante "addButton" con un nuovo metodo onAdd in MainFrame.cpp. Sono stati aggiunti al progetto i file PlanFrame.cpp, Mediator.cpp, PlanFrame.hpp e Mediator.hpp. È stato aggiunto un costruttore predefinito alla classe Plan in Plan.cpp e Plan.hpp. Sono state aggiunte nuove classi Mediator e PlanUpdater in Mediator.cpp e Mediator.hpp. Infine, è stata aggiunta una nuova classe PlanFrame in PlanFrame.cpp e PlanFrame.hpp.)
	void updateListBox(const wxString& str);
};

#endif // !MEDIATOR_HPP

#pragma once

class State
{

public:

	virtual ~State() = 0 {}

	virtual bool OnEnter() = 0;
	virtual State* Update() = 0;
	virtual bool Render() = 0;
	virtual void OnExit() = 0;

protected:

	struct Network
	{
		int m_selection;
		int m_victory;
	};

	Network lobbyChoice; //will contain whether player chooses to host or a join a room
	Network winner; //will contain winner of multiplayer match

};
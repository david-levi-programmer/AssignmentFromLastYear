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
		//TODO - Add variables to struct for ResultsState
	};
	//variable will contain whether player chooses to host or a join a room
	Network lobbyChoice;

};
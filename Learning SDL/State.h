#pragma once

class State
{

public:

	virtual ~State() = 0 {}

	virtual bool OnEnter() = 0;
	virtual State* Update() = 0;
	virtual bool Render() = 0;
	virtual void OnExit() = 0;

};
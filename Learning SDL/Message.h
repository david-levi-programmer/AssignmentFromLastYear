#pragma once

#include <string>
#include "GameObject.h"
#include "Text.h"

class Message : public GameObject
{

public:

	Message() {}
	virtual ~Message();

	void SetMessage(std::string message);

	virtual void Update() {}
	virtual void Render();

private:

	Text m_text;
	std::string m_message;

};
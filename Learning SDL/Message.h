#pragma once

#include <string>
#include "GameObject.h"
#include "Text.h"

class Message : public GameObject
{

public:

	Message(const std::string& message = "");
	virtual ~Message();

	virtual void Update() {}
	virtual void Render();

private:

	Text m_text;
	std::string m_message;

};
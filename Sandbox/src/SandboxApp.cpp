#include <Arcjet.h>

class Sandbox : public Arcjet::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Arcjet::Application* Arcjet::CreateApplication()
{
	return new Sandbox();
}
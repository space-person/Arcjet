#include <Arcjet.h>

class ExampleLayer : public Arcjet::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		AJ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Arcjet::Event& event) override
	{
		AJ_TRACE("{0}", event);
	}
};

class Sandbox : public Arcjet::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Arcjet::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Arcjet::Application* Arcjet::CreateApplication()
{
	return new Sandbox();
}
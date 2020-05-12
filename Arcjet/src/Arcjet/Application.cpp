#include "Application.h"

#include "Arcjet/Events/ApplicationEvent.h"
#include "Arcjet/Log.h"
namespace Arcjet
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280,720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AJ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AJ_TRACE(e);
		}

		while (true);
	}
}
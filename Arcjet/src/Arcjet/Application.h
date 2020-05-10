#pragma once

#include "Core.h"

namespace Arcjet
{

	class ARCJET_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
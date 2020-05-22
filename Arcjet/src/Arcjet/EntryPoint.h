#pragma once

#ifdef AJ_PLATFORM_WINDOWS

extern Arcjet::Application* Arcjet::CreateApplication();

int main(int argc, char** argv)
{
	Arcjet::Log::Init();
	AJ_CORE_WARN("Initialized Log !");

	auto app = Arcjet::CreateApplication();
	app->Run();
	delete app;
}

#endif
#pragma once

#ifdef AJ_PLATFORM_WINDOWS

extern Arcjet::Application* Arcjet::CreateApplication();

int main(int argc, char** argv)
{
	Arcjet::Log::Init();
	AJ_CORE_WARN("Initialized Log !");
	int a = 5;
	AJ_INFO("Hello ! Val={0}", a);

	auto app = Arcjet::CreateApplication();
	app->Run();
	delete app;
}

#endif
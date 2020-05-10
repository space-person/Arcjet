#pragma once

#ifdef AJ_PLATFORM_WINDOWS

extern Arcjet::Application* Arcjet::CreateApplication();

int main(int argc, char** argv)
{
	printf("Arcjet Engine, a personal learning project based on the Hazel engine by Yan Chernikov\n");
	auto app = Arcjet::CreateApplication();
	app->Run();
	delete app;
}

#endif
#include "Commander.h"
#include "logger.h"


	//RenderManager qRenderManager;
	//InputManager qInputManager;

	int Commander::init() {

		Log(INFO, "Initiating subsystems");


		std::cout << std::endl;
		Log(INFO, "Loading RenderManager");
		// Starting the RenderManager
		if (!RenderManager::startUp()) {
			Log(ERROR, "RenderManager failed to start properly.");
			return 0;
		}
		else { Log(INFO, "RenderManager successfully started."); }

		/*
		// Starting the InputManager
		if (!InputManager::startUp()) {
			Log(ERROR, "InputManager failed to start properly. |");
			return 0;
		}
		else { Log(INFO, "InputManager successfully started.   |"); }
		*/

	}
	
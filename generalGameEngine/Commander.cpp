#include "Commander.h"
#include "logger.h"


	RenderManager qRenderManager;
	InputManager qInputManager;

	int Commander::init() {

		Log(INFO, "Initiating subsystems");


		// Starting the RenderManager
		if (!qRenderManager.startUp()) {
			Log(ERROR, "RenderManager failed to start properly.");
			return -1;
		}
		else { Log(INFO, "RenderManager successfully started."); }

		// Starting the InputManager
		if (!qInputManager.startUp()) {
			Log(ERROR, "InputManager failed to start properly.");
			return -1;
		}
		else { Log(INFO, "InputManager successfully started."); }


	}
	
#include "Commander.h"
#include "logger.h"


	RenderManager qRenderManager;
	InputManager qInputManager;

	int Commander::init() {

		Log(INFO, "Initiating subsystems");


		std::cout << std::endl;
		Log(INFO, "Loading RenderManager");
		std::cout <<   "____________________________________________" << std::endl;
		// Starting the RenderManager
		if (!qRenderManager.startUp()) {
			Log(ERROR, "RenderManager failed to start properly.|");
			return 0;
		}
		else { Log(INFO, "RenderManager successfully started.  |"); }

		// Starting the InputManager
		if (!qInputManager.startUp()) {
			Log(ERROR, "InputManager failed to start properly. |");
			return 0;
		}
		else { Log(INFO, "InputManager successfully started.   |"); }
		std::cout <<  "--------------------------------------------" << std::endl;

	}
	
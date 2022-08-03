#include "logger.h"

void Log(Level level, const char* msg) {

	if (level == 0) {
		std::cout << "ERROR: " << msg << std::endl;
	}
	if (level == 1) {
		std::cout << "WARNING: " << msg << std::endl;
	}
	if (level == 2) {
		std::cout << "INFO: " << msg << std::endl;
	}
}
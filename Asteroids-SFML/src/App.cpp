#include "App.h"

App* App::getInstance() {
	if (instance == nullptr) instance = new App();
	return instance;
}

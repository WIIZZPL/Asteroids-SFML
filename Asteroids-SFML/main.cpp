#include <iostream>
#include "app.h"

int main() {
    App* app = App::getInstance();

    app->run();
}
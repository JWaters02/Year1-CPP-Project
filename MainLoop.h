/*
* HANDLES THE MAIN EVENT LOOP
*/

#ifndef SHOPPER_CPP_MAINLOOP_H
#define SHOPPER_CPP_MAINLOOP_H

#include <iostream>
#include <memory>
#include <windows.h>
#include "Stock.h"
#include "Commands.h"
#include "Logs.h"
#include "FileHandler.h"
#include "Order.h"

class MainLoop : Commands {
public:
    void mainEventLoop();
    void setTickSpeed(int _tickSpeed);
private:
    int tickSpeed = 500;
};

#endif //SHOPPER_CPP_MAINLOOP_H

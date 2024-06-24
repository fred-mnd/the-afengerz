#ifndef GLOBALS_CPP
#define GLOBALS_CPP

#include "globals.h"

namespace Globals{
    std::atomic<bool> gameOver{false};
    std::mutex timeline_mutex;
}

#endif

#include "Mediator.h"
#include "Logging/Logger/FileLog.h"
#include "Logging/Messages/GameMsg.h"

signed main() {
    auto* log = new FileLog;
    auto* msg = new GameMsg("govno");
    log->print(msg);
    //Mediator().start();
    delete log;

    return 0;
}
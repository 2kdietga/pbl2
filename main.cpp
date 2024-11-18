#include <iostream>
#include "file.hpp"
#include "room.h"
#include "user.h"
#include "service.h"

int main() {
    vector<room*> rooms = rfile<room>("rooms.txt");
    wfile<room>("rooms.out",rooms);
    return 0;
}

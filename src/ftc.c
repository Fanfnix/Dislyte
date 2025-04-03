#include "../include/header.h"

void initNcurses() {
    initscr();
    nodelay(stdscr, true);
    noecho();
    cbreak();
    curs_set(false);
}
#include "../include/header.h"

int main() {

    int l_schema = 3;
    float schema[] = {0.5, 0.75, 1};
    Skill * skill_1 = creerSkill(0, 0, "Competence-1", creerPattern(schema, l_schema));

    initscr();
    nodelay(stdscr, true);
    noecho();

    afficherSkill(stdscr, skill_1);

    mvwaddstr(stdscr, LINES-2, 2, ">>> Press any to leave ... ");

    while (getch() == -1);

    endwin();

    return 0;
}
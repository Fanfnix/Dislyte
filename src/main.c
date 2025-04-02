#include "../include/header.h"

int main() {

    int l_schema_1 = 2;
    float schema_1[] = {0.5, 0.5};
    Skill * skill_1 = creerSkill(0, 0, "Competence-1", creerPattern(schema_1, l_schema_1));

    int l_schema_2 = 1;
    float schema_2[] = {1.4};
    Skill * skill_2 = creerSkill(1, 0, "Competence-2", creerPattern(schema_2, l_schema_2));

    int l_schema_3 = 4;
    float schema_3[] = {0.6, 0.6, 0.6, 0.6};
    Skill * skill_3 = creerSkill(2, 0, "Competence-3", creerPattern(schema_3, l_schema_3));

    initscr();
    nodelay(stdscr, true);
    noecho();
    cbreak();
    curs_set(false);

    // afficherSkill(stdscr, skill_1);
    // afficherSkill(stdscr, skill_2);
    // afficherSkill(stdscr, skill_3);

    mvwaddstr(stdscr, LINES-2, 2, ">>> Press any to leave");

    while (getch() == -1);

    endwin();

    return 0;
}
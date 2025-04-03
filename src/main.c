#include "../include/header.h"

int main() {

    Skill * tab_skills_0[3];

    int l_schema_1 = 2;
    float schema_1[] = {0.5, 0.5};
    tab_skills_0[0] = creerSkill(0, 0, "Competence-1", creerPattern(schema_1, l_schema_1));

    int l_schema_2 = 1;
    float schema_2[] = {1.4};
    tab_skills_0[1] = creerSkill(1, 0, "Competence-2", creerPattern(schema_2, l_schema_2));

    int l_schema_3 = 4;
    float schema_3[] = {0.6, 0.6, 0.6, 0.6};
    tab_skills_0[2] = creerSkill(2, 0, "Competence-3", creerPattern(schema_3, l_schema_3));

    Stats * stats_0 = creerStats(6895, 855, 480, 0.1, 1.5, 0.2, 0.2);
    Esper * esper_0 = creerEsper(0, "Leora", stats_0, tab_skills_0);

    initNcurses();

    afficherEsper(stdscr, esper_0);

    mvwaddstr(stdscr, LINES-2, 2, ">>> Press 'k' to leave");

    while (getch() != 'k');

    endwin();

    return 0;
}
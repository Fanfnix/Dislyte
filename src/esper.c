#include "../include/header.h"


Esper * creerEsper(int id, char nom[], const Stats * base, Skill * skills[3]) {
    Esper * perso = malloc(sizeof(Esper));
    if (perso != NULL) {
        perso->id = id;
        strcpy(perso->nom, nom);
        if (base != NULL) perso->base = base; else printf("ERR : creerEsper(%d) Stats base null", id);
        if (skills != NULL) for (int i = 0; i < 3; i++) perso->skills[i] = skills[i]; else printf("ERR : creerEsper(%d) Skill skills null", id);
        return perso;
    } else printf("ERR : creerEsper(%d) failed\n", id);
    return NULL;
}


void boutonCompetence(WINDOW * competence, int id, int choisi) {
    char str[10];
    if (choisi) wattron(competence, A_BOLD);
    wborder(competence, '|', '|', '-', '-', '+', '+', '+', '+');
    sprintf(str, "C%d", id);
    mvwaddstr(competence, 1, 2, str);
    if (choisi) wattroff(competence, A_BOLD);
    wrefresh(competence);
}


void afficherEsper(WINDOW * win, Esper * esper) {
    int fenetre_esper_width = 40;
    int fenetre_esper_height = 30;
    WINDOW * fenetre_esper = derwin(win, fenetre_esper_height, fenetre_esper_width, 0, 0);
    wclear(fenetre_esper);
    wattron(fenetre_esper, A_BOLD);
    wborder(fenetre_esper, '|', '|', '-', '-', '+', '+', '+', '+');

    // Nom
    mvwaddstr(fenetre_esper, 1, (fenetre_esper_width-strlen(esper->nom))/2, esper->nom);
    wattroff(fenetre_esper, A_BOLD);

    // Stats
    int fenetre_esper_stats_width = fenetre_esper_width - 6;
    int fenetre_esper_stats_height = 7;
    WINDOW * fenetre_esper_stats = derwin(fenetre_esper, fenetre_esper_stats_height, fenetre_esper_stats_width, 3, 3);
    afficherStatsBase(fenetre_esper_stats, esper->base);

    // Skills
    int fenetre_esper_skills_width = fenetre_esper_width - 6;
    int fenetre_esper_skills_height = 3;
    WINDOW * fenetre_esper_skills = derwin(fenetre_esper, fenetre_esper_skills_height, fenetre_esper_skills_width, 11, 3);

    WINDOW * competence_1 = derwin(fenetre_esper_skills, 3, 6, 0, 5);
    WINDOW * competence_2 = derwin(fenetre_esper_skills, 3, 6, 0, 13);
    WINDOW * competence_3 = derwin(fenetre_esper_skills, 3, 6, 0, 21);

    int id = 0;
    char pressed = '\0';
    do {
        if (pressed == 'q') id--;
        if (pressed == 'd') id++;
        if (id > 2) id = 0;
        if (id < 0) id = 2;
        if (id == 0) {
            boutonCompetence(competence_1, 1, 1);
            afficherSkill(fenetre_esper, esper->skills[0]);
        } else boutonCompetence(competence_1, 1, 0);
        if (id == 1) {
            boutonCompetence(competence_2, 2, 1);
            afficherSkill(fenetre_esper, esper->skills[1]);
        } else boutonCompetence(competence_2, 2, 0);
        if (id == 2) {
            boutonCompetence(competence_3, 3, 1);
            afficherSkill(fenetre_esper, esper->skills[2]);
        } else boutonCompetence(competence_3, 3, 0);
        wrefresh(fenetre_esper);
    } while ((pressed = wgetch(fenetre_esper)) != 'k');
    wborder(fenetre_esper, '|', '|', '-', '-', '+', '+', '+', '+');

    // Refresh
    wrefresh(fenetre_esper);
}
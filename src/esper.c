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


void afficherEsper(WINDOW * win, Esper * esper) {
    int fenetre_esper_width = 40;
    int fenetre_esper_height = 30;
    WINDOW * fenetre_esper = derwin(win, fenetre_esper_height, fenetre_esper_width, 0, 0);
    wborder(fenetre_esper, '|', '|', '-', '-', '+', '+', '+', '+');

    // Nom
    wattron(fenetre_esper, A_BOLD);
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

    wborder(competence_1, '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(competence_2, '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(competence_3, '|', '|', '-', '-', '+', '+', '+', '+');
    
    mvwaddstr(competence_1, 1, 2, "C1");
    mvwaddstr(competence_2, 1, 2, "C2");
    mvwaddstr(competence_3, 1, 2, "C3");

    while (wgetch(fenetre_esper) != 'k') {
        
    }

    // Refresh
    wrefresh(fenetre_esper);
}
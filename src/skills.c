#include "../include/header.h"


Pattern * creerPattern(float schema[], int l_schema) {
    Pattern * pattern = malloc(sizeof(Pattern));
    if (pattern != NULL) {
        pattern->schema = schema;
        pattern->l_schema = l_schema;
        return pattern;
    } else printf("ERR : creerPattern() failed\n");
    return NULL;
}


char * genererDescription(Pattern * pattern) {
    char * description = malloc(500*sizeof(char));
    sprintf(description, "Attaque %d fois infligeant ", pattern->l_schema);
    if (pattern->l_schema > 1) strcat(description, "respectivement ");
    char tmp[50];
    for (int i = 0; i < pattern->l_schema; i++) {
        sprintf(tmp, "%.0f%%", 100*pattern->schema[i]);
        strcat(description, tmp);
        if (i == pattern->l_schema-1) strcat(description, " de l'ATK.");
        else if (i == pattern->l_schema-2) strcat(description, " et ");
        else strcat(description, ", ");
    }
    return description;
}


Skill * creerSkill(int id, int id_esper, char nom[], Pattern * pattern) {
    Skill * compet = malloc(sizeof(Skill));
    if (compet != NULL) {
        compet->id = id;
        compet->id_esper = id_esper;
        strcpy(compet->nom, nom);
        strcpy(compet->description, genererDescription(pattern));
        compet->pattern = pattern;
        return compet;
    } else printf("ERR : creerSkill(%d) failed\n", id);
    return NULL;
}


void afficherSkill(WINDOW * win, Skill * skill) {
    if (win != NULL && skill != NULL) {
        int fenetre_skill_width = 40;
        int fenetre_skill_height = 10;
        WINDOW * fenetre_skill = derwin(win, fenetre_skill_height, fenetre_skill_width, 0, 0);
        wborder(fenetre_skill, '|', '|', '-', '-', '+', '+', '+', '+');

        // Nom
        wattron(fenetre_skill, A_BOLD);
        mvwaddstr(fenetre_skill, 1, (fenetre_skill_width - strlen(skill->nom)) / 2, skill->nom);
        wattroff(fenetre_skill, A_BOLD);

        // Description
        int fenetre_skill_description_width = fenetre_skill_width - 4;
        int fenetre_skill_description_height = fenetre_skill_height - 5;
        WINDOW * fenetre_skill_description = derwin(fenetre_skill, fenetre_skill_description_height, fenetre_skill_description_width, 3, 2);
        mvwaddstr(fenetre_skill_description, 0, 0, skill->description);

        // Pattern
        char tmp[10];
        char str[50];
        sprintf(str, "( %.0f%%", 100*skill->pattern->schema[0]);
        for (int i = 1; i < skill->pattern->l_schema; i++) {
            sprintf(tmp, "%.0f%%", 100*skill->pattern->schema[i]);
            strcat(str, " / ");
            strcat(str, tmp);
        }
        strcat(str, " )");
        mvwaddstr(fenetre_skill, fenetre_skill_height-2, 2, str);

        // Refresh
        wrefresh(fenetre_skill);
    } else printf("ERR : afficherSkill() failed\n");
}
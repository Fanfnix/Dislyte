#include "../include/header.h"


Pattern * creerPattern(float ratio) {
    Pattern * pattern = malloc(sizeof(Pattern));
    if (pattern != NULL) {
        pattern->ratio = ratio;
        pattern->next = NULL;
        return pattern;
    } else printf("ERR : creerPattern() failed\n");
    return NULL;
}


Pattern * newPattern(float schema[], int l_schema) {
    Pattern *pattern, *pattern_tmp;
    for (int i = 0; i < l_schema; i++) {
        if (i == 0) {
            pattern = creerPattern(schema[0]);
            pattern_tmp = pattern;
        } else {
            pattern_tmp->next = creerPattern(schema[i]);
            pattern_tmp = pattern_tmp->next;
        }
    }
    return pattern;
}


Skill * creerSkill(int id, int id_esper, char nom[], char description[], Pattern * pattern) {
    Skill * compet = malloc(sizeof(Skill));
    if (compet != NULL) {
        compet->id = id;
        compet->id_esper = id_esper;
        strcpy(compet->nom, nom);
        strcpy(compet->description, description);
        compet->pattern = pattern;
        return compet;
    } else printf("ERR : creerSkill(%d) failed\n", id);
    return NULL;
}
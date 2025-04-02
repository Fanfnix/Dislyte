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
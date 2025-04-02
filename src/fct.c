#include "../include/header.h"

void ajouterPattern(Pattern * dst, Pattern * src) {
    Pattern * srctmp = src;
    Pattern * dsttmp = dst;
    while (srctmp != NULL) {
        dsttmp = srctmp
        dsttmp->next = srctmp->next;
        dsttmp = dsttmp->next;
    }
}

Skill * creerSkill(int id, int id_esper, char nom[], char description[], Pattern * pattern) {
    Skill * compet = malloc(sizeof(Skill));
    if (compet != NULL) {
        compet->id = id;
        compet->id_esper = id_esper;
        //strcpy(compet->nom, nom);
        //strcpy(compet->description, description);
        
        return compet;
    } else printf("ERR : creerSkill(%d) failed\n", id);
    return NULL;
}


Stats * creerStats(int pv, int atk, int def, int txcrit, int degcrit, int prec, int resist) {
    Stats * stat = malloc(sizeof(Stats));
    if (stat != NULL) {
        stat->pv = pv;
        stat->atk = atk;
        stat->def = def;
        stat->txcrit = txcrit;
        stat->degcrit = degcrit;
        stat->prec = prec;
        stat->resist = resist;
        return stat;
    } else printf("ERR : creerStat() failed\n");
    return NULL;
}


Esper * creerEsper(int id, char nom[], const Stats * base, Stats * bonus, Skill * skills[3]) {
    Esper * perso = malloc(sizeof(Esper));
    if (perso != NULL) {
        perso->id = id;
        strcpy(perso->nom, nom);
        if (base != NULL) perso->base = base; else printf("ERR : creerEsper(%d) Stats base null", id);
        if (bonus != NULL) perso->bonus = bonus; else printf("ERR : creerEsper(%d) Stats bonus null", id);
        if (skills != NULL) for (int i = 0; i < 3; i++) perso->skills[i] = skills[i]; else printf("ERR : creerEsper(%d) Skill skills null", id);
        return perso;
    } else printf("ERR : creerEsper(%d) failed\n", id);
    return NULL;
}
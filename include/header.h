#ifndef DISLYTE
#define DISLYTE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>


// SKILLS //

typedef struct Pattern {
    float * schema;
    int l_schema;
} Pattern;

typedef struct Skill {
    int id, id_esper;
    char nom[50];
    char description[500];
    struct Pattern * pattern;
} Skill;

Pattern * creerPattern(float schema[], int l_schema);
Skill * creerSkill(int id, int id_esper, char nom[], Pattern * pattern);
void afficherSkill(WINDOW * win, Skill * skill);


// STATS //

typedef struct Stats {
    int pv, atk, def, txcrit, degcrit, prec, resist;
} Stats;

Stats * creerStats(int pv, int ayk, int def, int txcrit, int degcrit, int prec, int resist);


// ESPER //

typedef struct Esper {
    int id;
    char nom[50];
    const struct Stats * base;
    struct Stats * bonus;
    struct Skill * skills[3];
} Esper;

Esper * creerEsper(int id, char nom[], const Stats * base, Stats * bonus, Skill * skills[3]);

#endif
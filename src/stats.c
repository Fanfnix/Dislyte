#include "../include/header.h"


Stats * creerStats(int pv, int atk, int def, float txcrit, float degcrit, float prec, float resist) {
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


void afficherStatsBase(WINDOW * win, const Stats * stats) {
    char str[50];
    // PV
    sprintf(str, "PV      : %d", stats->pv);
    mvwaddstr(win, 0, 0, str);
    // ATK
    sprintf(str, "ATK     : %d", stats->atk);
    mvwaddstr(win, 1, 0, str);
    // DEF
    sprintf(str, "DEF     : %d", stats->def);
    mvwaddstr(win, 2, 0, str);
    // TXCRIT
    sprintf(str, "TXCRIT  : %.0f %%", 100*stats->txcrit);
    mvwaddstr(win, 3, 0, str);
    // DEGCRIT
    sprintf(str, "DEGCRIT : %.0f %%", 100*stats->degcrit);
    mvwaddstr(win, 4, 0, str);
    // PREC
    sprintf(str, "PREC    : %.0f %%", 100*stats->prec);
    mvwaddstr(win, 5, 0, str);
    // RESIST
    sprintf(str, "RESIST  : %.0f %%", 100*stats->resist);
    mvwaddstr(win, 6, 0, str);
}
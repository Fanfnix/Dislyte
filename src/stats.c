#include "../include/header.h"


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
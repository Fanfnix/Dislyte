#include "../include/header.h"

int main() {

    float schema[] = {0.5, 0.75, 1};
    int l_schema = 3;
    Pattern * pattern = newPattern(schema, l_schema);
    Skill * skill_1 = creerSkill(0, 0, "Competence-1", "Description temporaire.", pattern);

    

    return 0;
}
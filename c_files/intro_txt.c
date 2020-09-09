/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** intro_txt
*/

#include "my.h"

const char *which_txt3(all_t *all, int i)
{
    if (i == 10)
        return "\tLe roi vous explique que vous etes la seule personne \
ayant survecu a cette bataille.\nIl poursuit en vous suppliant d'aller \
sauver sa fille.\nIl precise que selon lui cela doit etre un signe \
du destin \nque vous soyez toujours en vie.";
    else if (i == 11)
        return "\tVous acceptez la requete du roi et partez de ce pas \
a sa recherche. \nLe roi vous a aussi indiquez que le repere des ogres\nse \
trouve dans une grotte a l'ouest du royaume.";
}

const char *which_txt2(all_t *all, int i)
{
    if (i == 5)
        return "\tLe roi connaissant la cruaute de ces creatures place alors \
le royaume\nen etat d'urgence. Immediatement, il ordonne a la nouvelle \
garde\nroyale de voler au secours de sa fille.";
    if (i == 6)
        return "\tVous et le reste de la garde partez alors a la poursuite\n\
des ogres. Vous arrivez a les rattraper aux portes du royaume. \n\
S'en suit un combat acharne entre les chevaliers et ces creatures.";
    if (i == 7) {
        first_battle(all);
        sfSound_play(all->sd_first_battle);
        return "";
    } else if (i == 8) {
        return "\tVous vous evanouissez suite a cette bataille sans merci.";
    } else if (i == 9)
        return "\tPlusieurs jours se passent avant que  \
vous ne finissiez par vous reveiller. \nVous vous trouvez desormais dans \
une eglise. La guerisseuse s'etant occuper de vous, \ncourt chercher le roi \
pour le prevenir.";
    return which_txt3(all, i);
}

const char *which_txt(all_t *all, int i)
{
    if (i == 0)
        return "\tAujourd'hui, au royaume d'Indix, est un jour de fete. \n\
Il s'agit de la celebration de votre sacrement et de celui des autres \
chevaliers\ntout juste entres au service de la couronne.";
    else if (i == 1)
        return "\tLe roi Pehadare et sa fille, la princesse Eden, ont organise\
\nun banquet pour celebrer cet evenement.";
    else if (i == 2)
        return "\tMalheureusement, lors de ce banquet, les ogres, \n\
des creatures sans pitie vivant aux alentours du royaume, ont \
profiter\nde ces festivites pour kidnapper la princesse.";
    if (i == 3)
        return "\tGringork, leur chef, a ordonne a ses subordonnes de \
l'enlever dans le but\n de recuperer son collier qu'elle ne quitte jamais.";
    else if (i == 4)
        return "\tCe collier est compose d'un joyau au pouvoir extraordinaire.\
\nIl a la capacite de transformer les monstres en humains.";
    else
        return which_txt2(all, i);
}
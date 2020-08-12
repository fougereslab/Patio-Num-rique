# Espace dédié au développement du système de fontaine

La partie fontaine du projet comprend la commande de deux nébulisateur, la commande d'une pompe ainsi que de 4 électrovanne.
La commande de tous ces appareil se fait à partir d'une raspberry Pi 4

## Hardware

Il va falloir faire une carte électronique pour commandes les relais 5Vdc qui commande la pompe et les nébulisateur, les relais sont des relais finder avec support DIN pour rails, ils ne seront pas intégré à la carte.

La carte électronique aura également pour fonction de commander des électrovanne 12VDC avec des MOSFET, 4 au total, le but étant d'avoir une commutation rapide pour des effets d'eau plus impressionnant.

## Software

Il va falloir commander les jets d'eau, pouvoir programmer l'extinction de la pompe et des nébulisateurs. Et créer des fonctions de jeux d'eau préprogrammé pour jouer avec les jets d'eau.
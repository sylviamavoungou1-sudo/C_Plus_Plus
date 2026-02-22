# C_Plus_Plus

# Projet Polynômes et Traceur Graphique

## Description
Ce projet implémente une **classe Polynome en C++** permettant de :

- Créer des polynômes à partir de leur degré et de leurs coefficients.
- Additionner, soustraire des polynômes.
- Dériver un polynôme.
- Multiplication d'un polynome par un réel.
- Consulter et modifier les coefficients via l’opérateur `[]`.
- Calculer la valeur d’un polynôme pour un réel `x` avec l’opérateur `()`.
- Afficher un polynôme sur le terminal avec l’opérateur `<<`.

Il inclut également un **traceur graphique** utilisant la micro-bibliothèque EZ-Draw++ pour visualiser des fonctions ou polynômes.


## Structure des fichiers


├── calculatrice.cpp # Programme principal pour tester les opérations sur polynômes
├── traceur.cpp # Programme pour tracer des fonctions graphiquement
├── Polynome.hpp # Déclaration de la classe Polynome
├── Polynome.cpp # Implémentation de la classe Polynome
├── ez-draw++.hpp # Bibliothèque EZ-Draw (fournie)
├── ez-draw++.cpp # Bibliothèque EZ-Draw (fournie)
├── Makefile # Fichier de compilation
└── README.md # Ce fichier

## Compilation 
 Sous linux :

    make : compile tout le projet 
    make calculatrice : compile uniquement la calculatrice 
    make traceur : compile uniquement le traceur 
    make clean : permet de supprimer tout les fichiers objet 
    ./traceur : compile le traceur 
    ./calculatrice : compile la calculatrice

## Utilisation
    ! CALCULATRICE POLYNOME

- le programme affiche tout les 10 emplacements charger de stocker le Polynome
- un menu se met à votre disposition afin de choisir une action (saisir , additionner , soustraire , deriver , multiplication par un réel)
- Chaque action demande les informations sur votre polynome et l'emplacement dans lequel vous voulez le stocker
- L'affichage indique aucun "polynome" si vous n'avez rien stocker dans un emplacement

    ! TRACEUR DE FONCTION POLYNOME

-Les fonctions tracées peuvent être manipulées avec les flèches du clavier.

-Zoom : + / Dézoom : -

-Cliquez dans la fenêtre pour afficher les coordonnées du point.


# Projet realiser par Mlle MAVOUNGOU
# Projet encadre par Mr Remy
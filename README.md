# Bataille Navale - Modèle réduit en C

Ce projet est une implémentation du jeu **Bataille Navale** en langage C, jouable en **mode solo** ou **multijoueur local**. Il s'agit d'un projet d'entraînement visant à manipuler les bases du C (fonctions, tableaux, conditions, boucles, gestion utilisateur…) tout en réalisant un jeu complet en console.

---

## 🛠️ **Fonctionnalités**

- Placement des bateaux sur la grille
- Vérification de la validité des positions
- Mode **1 joueur (solo)**
- Mode **2 joueurs (local)**
- Gestion des tirs et affichage des touches / ratés
- Système de tour par tour
- Détection de fin de partie
- Menu principal propre et rejouable
- Affichage console (ASCII + couleurs)

---

## 📌 **Exemple d’affichage (console)**

T O U C H É !
Votre tir : B4

Grille ennemie :
~ ~ ~ X ~ ~ ~
~ ~ ~ ~ ~ ~ ~
~ ~ O ~ ~ ~ ~
~ ~ ~ ~ ~ ~ ~

---

## 💻 **Compilation et exécution**

### **Avec GCC (Linux / Mac / Windows + MinGW)**

Compilez :
```sh
gcc micro_bataille_ultime.c -o bataille_navale

./bataille_navale

Exécutez :

./bataille_navale

📂 Contenu du projet
Fichier	Description
micro_bataille_ultime.c	Code source principal
README.md	Documentation du projet
🚀 Pistes d’amélioration

IA plus intelligente en mode solo

Sauvegarde / chargement des parties

Mode réseau (TCP/IP)

Ajout d’animations ASCII

Interface graphique (SFML ou SDL) à long terme

📌 Pré-requis

Un compilateur C (GCC recommandé)

Un terminal compatible ANSI pour l’affichage des couleurs

👤 Auteur

Projet développé par Benjamin Zahavi — 2025

📜 Licence

Projet libre, utilisation personnelle autorisée.

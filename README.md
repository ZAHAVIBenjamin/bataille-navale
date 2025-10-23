# Micro Bataille Navale ⚓

Micro Bataille Navale est un jeu développé en **C**, permettant de jouer à la célèbre bataille navale contre l'ordinateur.  
Ce projet est réalisé dans un cadre pédagogique pour illustrer les notions de programmation structurée et de gestion de tableau.

---

## 🕹️ Règles du jeu

- Vous placez vos bateaux sur une grille.  
- Le but est de **couler tous les bateaux ennemis** avant que l’ordinateur ne coule les vôtres.  
- À chaque tour, vous donnez des coordonnées pour tirer et essayer de toucher un bateau adverse.  
- Le jeu continue jusqu’à ce qu’un camp ait coulé tous les bateaux adverses.

---

## ⚙️ Fonctionnalités

- Grille dynamique et affichage clair des tirs  
- Détection des collisions et des bateaux coulés  
- Gestion des tours joueur / ordinateur  
- Système de victoire automatique  
- Couleurs et messages clairs pour l’expérience utilisateur

---

## 💻 Installation & Exécution

Pour compiler et lancer le programme sous **Windows / PowerShell** :

```powershell
gcc micro_bataille_ultime.c -o micro_bataille_ultime
.\micro_bataille_ultime

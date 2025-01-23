# Snake And Ladder

## 1er projet C (2024-2025)
***30-12-2024*** : J'ai choisi ce projet pour apprendre le C, le but est qu'à terme il y ait un GUI

## Dépendance
- <a href="https://www.libsdl.org/"> SDL </a>
- <a href="https://wiki.libsdl.org/SDL3_image/FrontPage"> SDL_image </a>

### Journal
- ***30-12*** : J'ai crée la version text du jeu. On peut joueur jusqu'à 4 joueur ou seul contre l'ordi.
- ***08-01*** : J'ai un 2e fichier qui crée une fenêtre vide pendant une second"
- ***10-01*** : J'ai enfin un programme qui peut afficher des images grace à SDL_image. J'ai mis la code 'main' en commentaire pour m’occuper que de SDL et j'ai crée un fichier 'constant.h'.
- ***14-01*** : Il faut que l'image de fond soit de 500x500 car je n'arrive pas à la redimensionner. J'ai mis en place la gestion des événements.
- ***15-01*** : J'ai crée le fichier 'player' qui affiche les 4 joueurs.
- ***16-01*** : J'ai mis en place le déplacement sur la 1re ligne pour les joueurs.
- ***17-01*** : J'ai mis en place un déplacement correct qui change de sens correctement.
- ***18-01*** : Il y a un algo qui sort toujours un nombre different entre 0 et 6. J'ai séparer le code source en 2 fichiers "src" pour les '.c' et "header" pour les '.h' . J'ai un peu nettoyer les partie de code que j'avais mis en commentaire.
- ***19-01*** : J'ai corriger la limite pour ne pas dépasser la fin (100) et le déplacement se fait maintenant de bas en haut. J'ai fait un visuel paint du boutons et de du background.
- ***20-01*** : J'ai mis en place les échelle mais les serpents ne t’amène pas au bon endroit.
- ***21-01*** : J'ai retravailler la fonction qui calcul la nouvelle position des joueurs.
- ***22-01*** : J'ai fini de mettre en place toutes les échelles et les serpents. Le background change de couleur en fonction du joueur qui est en train de jouer. On peut jouer contre l'ordi comme si on joue a 2 joueurs.
- ***23-01*** : J'ai animé le déplacement des joueurs !!!

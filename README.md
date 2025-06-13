Fonctions principales de la mlx :

- mlx_init() : initialise la mlx et retourne un pointeur de la mlx
- mlx_new_window() : créer la fenêtre (taille, titre) et retourne un pointeur de cette fenêtre
- mlx_new_image() : réserve l'espace dans la mémoire pour l'image
- mlx_get_data_addr() : récupérer les infos de l'image et ça va la préparer pour qu'elle soit affichée ensuite (en quelque sorte ça créer l'image virtuellement dans la mémoire)
- mlx_loop_hook() : ça va dire à la mlx qu'à chaque boucle (loop) il faudra executer cette fonction et y passer ces paramètres
- mlx_loop() : ça déclenche la boucle (loop), le programme ne continue pas plus loin tant que la boucle est active. On dit d'un tour de boucle un "tick"
- mlx_hook() : ça permet d'ajouter des évenements (ex avec keypress ça permet d'éffectuer une fonction à chaque fois qu'un touche est appyé)
- mlx_put_image_to_window() : copie l'image (ou dessine) dans la fenêtre

Les autres fonctions importantes :

- atan2() : ça permet de trouve l'angle / direction vers laquel le joueur regarde (ex : si la pos du joueur est x=0 et y=-1 alors le joueur regarde à -PI/2 donc à gauche)
- cos() / sin() : ça permet de calculer la future distance, cos pour le x et sin pour le y (grossomodo avec l'orientation + angle et la vitesse on peut savoir ou sera sur le plan 2D le point du joueur)
-

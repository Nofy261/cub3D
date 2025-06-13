/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:12:01 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 11:05:39 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ajout d'un nouveau structure pour le raycasting


// On projette des rayons dans le champ de vision
// On calcule où ils frappent un mur
// On choisit la bonne texture selon le mur
// On calcule comment afficher la texture
// On dessine le rendu sur la fenêtre

// 1-Calcul du nombre de rayons et de l’angle entre chaque rayon
// 2-Pour chaque rayon (de gauche à droite dans l’écran) :
//   a. Calculer l’angle exact du rayon
//   b). Détecter la collision du rayon avec un mur
//   c. Choisir la bonne texture à appliquer
//   d. Calculer la position dans la texture pour un mapping correct
//   e. Dessiner la colonne verticale de pixels à l’écran
// 3-Répéter pour tous les rayons


// Parcourir chaque colonne de l’écran.
// Calculer l’angle du rayon.
// Lancer un rayon jusqu’à rencontrer un mur.
// Corriger la distance avec l’angle (anti fish-eye).
// Calculer la hauteur du mur.
// Dessiner la colonne avec la bonne texture.
// Répéter pour tout l’écran.





// void raycast()
// {
        


    
// }
# Reconfiguration rapide de systèmes de production robotisés

> Configuration des entrées sorties des trois automates de l'ensemble de la cellule flexible de l'aip - 2019.
> Le fichier "Platine Automate.zip" contient trois fichier permettant de configurer la mémoire partagée des automates de la cellule flexible.


## Auteurs
- __Mekkid Oussama__ -- oussama.mekkid@gmail.com
- __Moumene Malek__ -- malekmoumene@gmail.com
- __Brisbare Kevin__ -- kevin.brisbare@gmail.com
- __Orbach Mano__ -- orb.mano@gmail.com
- __Monneret Viven__ -- vivien.monneret@univ-tlse3.fr
- __Meliouh Yles__ -- ylesmeliouh@gmail.com


# TO DO

1. **Ouvrir le fichier "platine_automate_X" avec "X" correspondant au numéro des automates (2, 3 ou 4)**

2. **Aller dans "Automate", puis "Définir l'adresse..."**

3. **Définir l'adresse de l'automate dans le module "Adresse" de la partie automate avec l'adresse IP suivante**
	- 192.168.0.102 pour l'automate 2
	- 192.168.0.103 pour l'automate 3
	- 192.168.0.104 pour l'automate 4

4. **Valider en cliquant sur "OK"**

5. **Décharger le projet et le transférer dans l'automate en cliquant sur "Décharger le projet"**

6. **Une fois le projet décharger et générer, il suffit d'exécuter le projet en cliquant sur "Run"**

## Remarques

> Vérifier que l'ensemble des capteurs et des actionneurs soient bien brassés sur les bonnes entrées et sorties de automate correspondant.
> Ce fichier contient aussi les scenarios de test validant une communication entre la cellule flexible avec le robot Kuka.

> L'onglet "Variables élémentaires" dans les programmes unity pro contient des getters et des setters qui permettent d'obtenir/modifier les capteurs et actionneurs de l'automate.

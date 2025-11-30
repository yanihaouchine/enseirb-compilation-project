On a réalisé un compilateur qui comprend:
    1. Gestion des expressions arithmétiques entières avec constantes 
    2.Gestion des constantes flottantes, gestions des types INT et FLOAT avec conversion de type INT vers FLOAT
    3.Gestion des variables globales 
    4.Gestion des structures de contrôles
    5.gestion des booléens paresseux 
    6.Gestion des sous-blocs et des variables locales 
    7.Gestion des fonctions simples, non récursives et sans sous-blocs
    8.Gestion des fonctions typées, non récursives et sans sous-blocs
    9.Gestion des fonctions non récursives avec sous-blocs
    10.Gestion des fonctions récursives générales
    11.Gestion des fonctions mutuellement récursives générales

On a également:
    -ajouter une fontion dans aux.y pour gérér les instructions 
    - changé la grammaire pour faciliter l'implémentation des fonctions mutuellement recursive

    - géré les erreurs pour les cas suivants:
    
    	si une fonction declarer void et return un int ou float
        si une fonction declarer int et return un float
        si une fonction déclarer foat et return un int
        si déclare int ou float et on return rien




Pour compiler le projet:
$ make

Pour nettoyer le projet:
$ make clean

Pour lancer le compilateur:


La commande qui lance tous les tests:
$ ./compile_all.sh


Remarque :
Notre compilateur ne permet pas d’appeler une fonction avec des paramètres dans un ordre différent de celui défini lors de sa déclaration.

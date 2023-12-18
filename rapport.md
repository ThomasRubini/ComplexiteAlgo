I)

1)
# Tri par sélection:
Dans le tri par sélection, la liste est séparée en 2 parties: la partie non triée (à gauche), et la partie triée (à droite, qui gagne 1 de taille à chaque itération)
A chaque itération, nous trouvons le nombre le plus petit de la liste. Puis, nous étendons la partie triée de 1 sur la gauche, et nous échangeons ce nouvel élément de la liste triée avec celui que nous venons de trouver (le plus petit de la liste non trié)

# Tri fusion (Merge sort)
Le tri fusion est un algorithme récursif qui fonctionne sur la base de "Diviser pour mieux régner". Dans cet algorithme, nous divisons la liste en 2 parties égales, que nous divisons encore, jusqu'a obtenir des listes de taille 1 (qui sont donc triées). Ensuite, nous fusionnons les listes triées jusqu'a reformer la liste initiale (mais triée).

# Tri à bulles
A chaque itération, cet algorithme va comparer les éléments côte-à-côte de la liste, et les inverser si le premier est plus grand que le second. Ainsi, on peut garantir qu'après chaque itération `i`, les `i` derniers éléments de la liste seront triés.
L'algorithme s'arrête quand il fini une itération sans avoir besoin d'inverser des éléments

# Tri rapide (quicksort)
Le tri rapide est un algorithme récursif qui fonctionne sur la base de "Diviser pour mieux régner". Il sélectionne un pivot dans la liste, puis partitionne la liste de facon à ce que tout les éléments avant le pivot soient plus petits que lui, et que tout les éléments avant le pivot soient plus grands que lui. Cette opération est ensuite répétée sur les 2 sous-listes crées, jusqu'a obtenir des listes de taille 1.

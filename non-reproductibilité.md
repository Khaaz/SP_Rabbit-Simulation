# Compte rendu de non reproductibilité Simulation Croissance de lapins

## Raisons de la non reproductibilité

### Hypothèse 1 : Version du compilateur

Cette hypothèse semble validée par les différents tests suivants :

Tous ces exemples utilise `runMany(1, 7, 10, 100)`.
### **gcc version 6.3.0 :**


```
Esperance de vie: 4.7194
Population finale: 302455
Nombre de mort total: 108644
Nombre de naissances total: 411079
Moyenne du nombre de portees: 6.00359
Plus vieux lapin de la simulation: 7 ans et 0 mois

ANNEE: 1
Population: 43
Nombre de naissances: 39
Nombre de morts: 16
% accroissement de la pop: 115
Multiplicateur de la pop: 2.15

ANNEE: 2
Population: 243
Nombre de naissances: 269
Nombre de morts: 69
% accroissement de la pop: 465.116
Multiplicateur de la pop: 5.65116

ANNEE: 3
Population: 1030
Nombre de naissances: 1026
Nombre de morts: 239
% accroissement de la pop: 323.868
Multiplicateur de la pop: 4.23868

ANNEE: 4
Population: 4025
Nombre de naissances: 4137
Nombre de morts: 1142
% accroissement de la pop: 290.777
Multiplicateur de la pop: 3.90777

ANNEE: 5
Population: 16819
Nombre de naissances: 17493
Nombre de morts: 4699
% accroissement de la pop: 317.863
Multiplicateur de la pop: 4.17863

ANNEE: 6
Population: 71618
Nombre de naissances: 74552
Nombre de morts: 19753
% accroissement de la pop: 325.816
Multiplicateur de la pop: 4.25816

ANNEE: 7
Population: 302455
Nombre de naissances: 313563
Nombre de morts: 82726
% accroissement de la pop: 322.317
Multiplicateur de la pop: 4.22317
TIME: 6117ms

```
```
Simulation sur 7 annees.

Esperance de vie: 4.6896
Population finale: 318387
Nombre de mort total: 114899
Nombre de naissances total: 433266
Moyenne du nombre de portees: 6.00629
Plus vieux lapin de la simulation: 5 ans et 10 mois

ANNEE: 1
Population: 43
Nombre de naissances: 39
Nombre de morts: 16
% accroissement de la pop: 115
Multiplicateur de la pop: 2.15

ANNEE: 2
Population: 243
Nombre de naissances: 269
Nombre de morts: 69
% accroissement de la pop: 465.116
Multiplicateur de la pop: 5.65116

ANNEE: 3
Population: 1042
Nombre de naissances: 1044
Nombre de morts: 245
% accroissement de la pop: 328.807
Multiplicateur de la pop: 4.28807

ANNEE: 4
Population: 4160
Nombre de naissances: 4255
Nombre de morts: 1137
% accroissement de la pop: 299.232
Multiplicateur de la pop: 3.99232

ANNEE: 5
Population: 17436
Nombre de naissances: 18165
Nombre de morts: 4889
% accroissement de la pop: 319.135
Multiplicateur de la pop: 4.19135

ANNEE: 6
Population: 73963
Nombre de naissances: 76905
Nombre de morts: 20378
% accroissement de la pop: 324.197
Multiplicateur de la pop: 4.24197

ANNEE: 7
Population: 318387
Nombre de naissances: 332589
Nombre de morts: 88165
% accroissement de la pop: 330.468
Multiplicateur de la pop: 4.30468
TIME: 8170ms

```

On voit que même sur le même poste avec la meme version de G++(6.3.0), nous avons des résultats différents à chaque fois.

### **gcc version 8.3.0 :**

Nous avons ensuite upgrade jusqu'à la version 8.3.0.

Plus de problèmes de reproductivité sur le même poste cependant toujours un problème sur deux postes différents :

Louison:
```
Simulation sur 7 annees.

Esperance de vie: 4.68353
Population finale: 183084
Nombre de mort total: 66353
Nombre de naissances total: 249417
Moyenne du nombre de portees: 6
Plus vieux lapin de la simulation: 6 ans et 5 mois

ANNEE: 1
Population: 11
Nombre de naissances: 0
Nombre de morts: 9
% accroissement de la pop: -45
Multiplicateur de la pop: 0.55

ANNEE: 2
Population: 98
Nombre de naissances: 139
Nombre de morts: 52
% accroissement de la pop: 790.909
Multiplicateur de la pop: 8.90909

ANNEE: 3
Population: 561
Nombre de naissances: 622
Nombre de morts: 159
% accroissement de la pop: 472.449
Multiplicateur de la pop: 5.72449

ANNEE: 4
Population: 2457
Nombre de naissances: 2509
Nombre de morts: 613
% accroissement de la pop: 337.968
Multiplicateur de la pop: 4.37968

ANNEE: 5
Population: 10169
Nombre de naissances: 10525
Nombre de morts: 2813
% accroissement de la pop: 313.879
Multiplicateur de la pop: 4.13879

ANNEE: 6
Population: 42569
Nombre de naissances: 44319
Nombre de morts: 11919
% accroissement de la pop: 318.615
Multiplicateur de la pop: 4.18615

ANNEE: 7
Population: 183084
Nombre de naissances: 191303
Nombre de morts: 50788
% accroissement de la pop: 330.088
Multiplicateur de la pop: 4.30088
TIME: 7036ms
```

Alexandre :
```
Simulation sur 7 annees.

Esperance de vie: 4.68353
Population finale: 183084
Nombre de mort total: 66353
Nombre de naissances total: 249417
Moyenne du nombre de portees: 6
Plus vieux lapin de la simulation: 6 ans et 5 mois

ANNEE: 1
Population: 11
Nombre de naissances: 0
Nombre de morts: 9
% accroissement de la pop: -45
Multiplicateur de la pop: 0.55

ANNEE: 2
Population: 98
Nombre de naissances: 139
Nombre de morts: 52
% accroissement de la pop: 790.909
Multiplicateur de la pop: 8.90909

ANNEE: 3
Population: 561
Nombre de naissances: 622
Nombre de morts: 159
% accroissement de la pop: 472.449
Multiplicateur de la pop: 5.72449

ANNEE: 4
Population: 2457
Nombre de naissances: 2509
Nombre de morts: 613
% accroissement de la pop: 337.968
Multiplicateur de la pop: 4.37968

ANNEE: 5
Population: 10169
Nombre de naissances: 10525
Nombre de morts: 2813
% accroissement de la pop: 313.879
Multiplicateur de la pop: 4.13879

ANNEE: 6
Population: 42569
Nombre de naissances: 44319
Nombre de morts: 11919
% accroissement de la pop: 318.615
Multiplicateur de la pop: 4.18615

ANNEE: 7
Population: 183084
Nombre de naissances: 191303
Nombre de morts: 50788
% accroissement de la pop: 330.088
Multiplicateur de la pop: 4.30088
TIME: 2381ms
```

Remarque:
La compilation sous CLION avec la tool chain de visual studio en version 16.0 et cmake en version 3.17.3 donne encore des résulats différents.

La compilation sous CLION avec la tool chain MinGW en version 5.0 et cmake en version 3.17.3 donne un resultat encore différent.


### Hypothèse 2 : Précision

Nous avons fait l'erreur au départ de garder des floats . Nous avons tenté d'augmenter la précision de nos nombres à virgules en passant de float à double cependant aucun changement n'as pu être remarqué.

### Hypothèse 3 : La façon de gérer les seeds
Nous ne sommes pas sur de la façon dont nous gérons les seeds. En effet, celle ci est statique et changée a chaque nouvelle simulation.
Malgrès tout, même sans changement de seed, nous avons les memes problèmes.


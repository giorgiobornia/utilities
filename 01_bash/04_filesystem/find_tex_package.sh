#!/bin/bash

texhash > texdirs
grep ls-R
#parti da li' e trovi il primo spazio bianco all'indietro
# cosi' e' piu' generale che saltare le prime due parole "texhash: Updating"

oppure prima puoi fare 
locate ls-R
cosi trovi il database in cui cercare
Poi devi anche togliere quelli che sono link, e lo scopri facendo
ls -l `locate ls-R`
Una volta trovato il database devo fare la ricerca del nome del pacchetto all'interno di tale database


locate (o find) in questi percorsi



Il modo diretto potrebbe fare un minifile di latex in cui inserisco soltanto \usepackage{} e vedo se dice 'file not found'.
Ma cosi' non va bene, perche' ci sono dei pacchetti che sono per le document class


---------- In realta' basta usare "kpsewhich"!

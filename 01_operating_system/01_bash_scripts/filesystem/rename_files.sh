#!/bin/bash
#notare che in questo c'e' il modo per aumentare il contatore del ciclo do, e inoltre bisogna mettere le virgolette quando i file hanno dei nomi con gli spazi dentro.


k=1;
for file in photo*.jpg;
 do mv "./$file" ./primephoto$k.jpg;
 ((k++));
 echo $k;
 done
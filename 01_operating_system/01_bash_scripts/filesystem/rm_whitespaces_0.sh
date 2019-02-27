#!/bin/bash

# put underscore instead of spaces in file names

for file in *
 do
     mv "$file"  ` echo "$file" | sed 's/ /_/g' `  
 done



# le DOUBLE quotes (weak quotes) intorno al primo $file sono FONDAMENTALI!!!
# in questo modo interpreta gli spazi come semplici caratteri e non come field separator

# anche le SINGLE quotes (strong quotes) intorno all'argomento di sed sono fondamentali.
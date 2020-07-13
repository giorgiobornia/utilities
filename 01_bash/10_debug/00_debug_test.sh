#!/bin/bash

# You need to pass the -x or -v argument to bash

# turn on debug mode with x
set -x


echo Cleaning the out directory 


# turn OFF debug mode  with x
set +x


mkdir -p out
cd out

# turn on debug mode with v
set -v

# turn OFF debug mode  with v
set +v

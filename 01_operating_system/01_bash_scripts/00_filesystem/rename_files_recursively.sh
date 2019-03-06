#!/bin/bash
#the purpose of this script is to rename files inside each directory
#What would happen if I did
#  mv Caso*/*.h5 Caso*/sol.200.h5
# ??
# How does * work? Does it make all the possible combinations?
#Yes, every * is independent.
#See what it will do...
# giorgio@diamante:~/Projects/FEMcfd/libmesh-0.6.4/libmesh/examples/ansccv1/tests/mhd/Casi> mv Caso*/*.h5
# sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5
# giorgio@diamante:~/Projects/FEMcfd/libmesh-0.6.4/libmesh/examples/ansccv1/tests/mhd/Casi> mv Caso*/*.h5 Caso*/sol.200.h5
# sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5  sol.200.h5
k=1
while ((k < 13))
do
  mv Caso$k/*.xmf Caso$k/sol.200.xmf;
  let k++
done
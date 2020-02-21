 
# set xrange [-5:5]
# set yrange [-5:5]
# dx(x) = x
# dy(x) = 2*x
# plot "++" using 1:2:(dx($1)):(dy($2)) w vec



set xrange [-5:5]
set yrange [-5:5]
# only integer x-cordinates
set samples 11
# only integer y-cordinates
set isosamples 11
# we need data, so we use the special filename "++", which
# produces x,y-pairs
plot "++" using 1:2:1:(2.*$2) with vectors

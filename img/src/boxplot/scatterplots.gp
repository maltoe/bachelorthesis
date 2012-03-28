set terminal pngcairo enhanced
set ylabel 'runtime (new)'
set xlabel 'runtime (old)'

set samples 10000

set output 'scatter_geolat3.png'
plot 'geolat3.dat' using 2:3 title 'geo3 (3 anchors)', x/2.20 title 'calculated average speed up'  

set output 'scatter_geolat4.png'
plot 'geolat3.dat' using 2:3 title 'geo3 (4 anchors)', x/2.22 title 'calculated average speed up'  

set output 'scatter_geolat5.png'
plot 'geolat5.dat' using 2:3 title 'geo3 (5 anchors)', x/2.18 title 'calculated average speed up'  

set output 'scatter_aml3.png'
plot 'aml3.dat' using 2:3 title 'aml (3 anchors)', x/2.70 title 'calculated average speed up'  

set output 'scatter_aml4.png'
plot 'aml4.dat' using 2:3 title 'aml (4 anchors)', x/2.91 title 'calculated average speed up'  

set output 'scatter_aml5.png'
plot 'aml5.dat' using 2:3 title 'aml (5 anchors)', x/3.01 title 'calculated average speed up'  

set output 'scatter_vble3.png'
plot 'vble_opt3_filtered.dat' using 2:3 title 'vble_opt (3 anchors)', x/1.64 title 'calculated average speed up (error)'  

set output 'scatter_vble4.png'
plot 'vble_opt4.dat' using 2:3 title 'vble_opt (4 anchors)', x/1.77 title 'calculated average speed up' 

set output 'scatter_vble5.png'
plot 'vble_opt5.dat' using 2:3 title 'vble_opt (5 anchors)', x/1.75 title 'calculated average speed up' 

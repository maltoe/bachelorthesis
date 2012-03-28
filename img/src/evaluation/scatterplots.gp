set term postscript eps color blacktext "Helvetica" 16
set ylabel 'optimized runtime (s)'
set xlabel 'reference runtime (s)'

set style line 2 lt 1 lc rgb "green" lw 2.5

set output 'scatter_geolat3.tmp.eps'
plot 'geolat3.dat' using 2:3 title 'Geo3', x/2.20 title 'calculated average speed-up' linestyle 2  
set output
!sed -e 's|/DOCINFO pdfmark||' < scatter_geolat3.tmp.eps > scatter_geolat3.eps

# Note that we add some jitter to the aml data since we have so many duplicates.
set output 'scatter_aml4.tmp.eps'
plot 'aml4.dat' using ($2+rand(0)*0.004):($3+rand(0)*0.004) title 'AML (4 anchors)', x/2.91 title 'calculated average speed-up' linestyle 2 
set output
!sed -e 's|/DOCINFO pdfmark||' < scatter_aml4.tmp.eps > scatter_aml4.eps

# Set ranges to compare vble3/4.
set xrange [15:50]
set yrange [5:35]

set output 'scatter_vble3.tmp.eps'
plot 'vble_opt3_filtered.dat' using 2:3 title 'VBLE-OPT (3 anchors)', x/1.64 title 'calculated average speed up' linestyle 2 
set output
!sed -e 's|/DOCINFO pdfmark||' < scatter_vble3.tmp.eps > scatter_vble3.eps

set output 'scatter_vble4.tmp.eps'
plot 'vble_opt4.dat' using 2:3 title 'VBLE-OPT (4 anchors)', x/1.77 title 'calculated average speed up' linestyle 2 
set output
!sed -e 's|/DOCINFO pdfmark||' < scatter_vble4.tmp.eps > scatter_vble4.eps

!rm *.tmp.eps
!mv *.eps ../../

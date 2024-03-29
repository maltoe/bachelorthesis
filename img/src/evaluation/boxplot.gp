set term postscript eps color blacktext "Helvetica" 16
set output 'boxplot.tmp.eps'

set size 1.0,1.4

# border
set border 2 front linetype -1 linewidth 1.000
set style fill solid 0.25 border lt -1
unset key

# boxplot config
set style data boxplot
set style boxplot range 2.0
set boxwidth 0.3 absolute

# Linestyles
set style line 1 lt rgb "red" lw 1 pt 7 ps 0.4 
set style line 2 lt 1 lc rgb "orange" lw 1 pt 7 ps 0.4
set style line 3 lt 1 lc rgb "violet" lw 1 pt 7 ps 0.4

# axis
set xtics border in scale 0,0 nomirror norotate offset character 0, 0, 0 autojustify
set xtics norangelimit
set xtics ("AML" 1.20000, "Geo3" 2.8, "VBLE-OPT" 4.4)
#set ytics border in scale 1,0.25 norotate offset character 0, 0, 0 autojustify
set ytics 1,0.25 nomirror autojustify
set yrange [ 1.00000 : 4.000 ] noreverse nowriteback
set ylabel "speed-up"

set grid ytics

plot 'aml3.dat' using (0.6):4 linestyle 1, \
     'aml4.dat' using (1.2):4 linestyle 1, \
     'aml5.dat' using (1.8):4 linestyle 1, \
     'geolat3.dat' using (2.8):4 linestyle 2, \
     'vble_opt3_filtered.dat' using (3.8):4 linestyle 3, \
     'vble_opt4.dat' using (4.4):4 linestyle 3, \
     'vble_opt5.dat' using (5.0):4 linestyle 3

# Fix eps file:
set output
!sed -e 's|/DOCINFO pdfmark||' < boxplot.tmp.eps > boxplot.eps
!rm boxplot.tmp.eps
!mv boxplot.eps ../../


set terminal png size 1280,941 crop 
set output 'testimage.png'

set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12

set xlabel "TAMANHO [int]"
set ylabel "TEMPO [MILISEGUNDOS]"
set title "ORG GRAPH"

set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.5

set style line 2 \
    linecolor rgb '#dd181f' \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.5

plot 'func1.tmp' with linespoints linestyle 1, \
     'func2.tmp' with linespoints linestyle 2
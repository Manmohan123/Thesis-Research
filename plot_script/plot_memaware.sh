
ALPHAS="1.01 1.1 1.5 2 4 8 16"
#ALPHAS="16"
M=360
rho1=1.3
rho2=1.3

for alpha in $ALPHAS
do
    for model in 1 2 3
    do
	./plot-memaware ${model} ${M} ${alpha} ${rho1} ${rho2} > model-mem_${model}_${alpha}_${rho1}_${rho2}
    done
done


for alpha in $ALPHAS
do
    GNUPLOTLINE="${GNUPLOTLINE} set logscale;"
    GNUPLOTLINE="${GNUPLOTLINE} set xrange [1: ${M}];"
    GNUPLOTLINE="${GNUPLOTLINE} set yrange [1: ${M}];"
    GNUPLOTLINE="${GNUPLOTLINE} set title 'm=$M alpha=$alpha';"
    GNUPLOTLINE="${GNUPLOTLINE} plot "
    for model in 1 2 3
    do
	GNUPLOTLINE="${GNUPLOTLINE} 'model-mem_${model}_${alpha}_${rho1}_${rho2}' t 'model ${model}', "
    done
    GNUPLOTLINE="`echo $GNUPLOTLINE | sed 's/,$//'`;"

done


gnuplot <<EOF

set terminal pdf;
set output 'plot-mem.pdf';

set xlabel 'cmax';
set ylabel 'mem'

$GNUPLOTLINE

EOF

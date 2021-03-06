

ALPHAS="1.1 1.5 2"
#ALPHAS="2"
M=210

for alpha in $ALPHAS
do
    for model in 1 2 3
    do


./plot ${model} ${M} $alpha > model_${model}_${alpha}
    done
done


for alpha in $ALPHAS
do
    GNUPLOTLINE="${GNUPLOTLINE} set title 'm=$M alpha=$alpha';"
    GNUPLOTLINE="${GNUPLOTLINE} plot "
    for model in 1 2 3
    do
	GNUPLOTLINE="${GNUPLOTLINE} 'model_${model}_${alpha}' t 'model ${model}', "
    done
    GNUPLOTLINE="`echo $GNUPLOTLINE | sed 's/,$//'`;"

done


gnuplot <<EOF

set terminal latex size 7cm, 5cm;

set output 'plot.tex';

set xlabel 'Replication';
set ylabel 'Ratio'

$GNUPLOTLINE

EOF

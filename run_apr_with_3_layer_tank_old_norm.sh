
#!/bin/bash

N=10
export L='7'
export I='24'
export IT='5'
export OFF='0'
export MIXING_LEVELS='3'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM
export BUFFER_LEVELS='3'
export RADIUS='0.2'
export HEIGHT='0.6'

#running feb week
export MONTH='4'
export DAY='4'
export Norm_old='0.130'

export C=0
for R in 1200 2400 4800; do
export  RUNS="$R" 

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm_new_old_norm_all.sh ; done

done
done

#running feb week

#running feb week

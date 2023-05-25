# OnlineHeatingControl

The set of environment variables that needs to be set before running the experiments

```bash
export START_DATA='2 3 0 1 0'
export WEIGHT_VALUES='0.5 0.5 13.856'
export SET_RUNS='200 1'
```
## Experiment Examples

To run the experiments for a specific period, we need  *normalization factor* for that specific period

### Example1: February week (days 4-10)

The *normalization factor* for February 4-10 is 6.828. To run the experiment with *alpha = 0.0* and *gamma = 1.0*, you need to use the following commands

```bash
export START_DATA='2 4 0 7 0'
export WEIGHT_VALUES='0.0 1.0 6.828'
export SET_RUNS='600 5'
for i in {1..10}; do sbatch run_EM_verifyta_slurm.sh ; done
```

To use different combination of *alpha* and *gamma* in next experiment, you just need to update *WEIGHT_VALUES* env variable as other variables are already set

```bash
export WEIGHT_VALUES='0.1 0.9 6.828'
for i in {1..10}; do sbatch run_EM_verifyta_slurm.sh ; done
```

### Example2: January week (days 4-10)

The *normalization factor* for January 4-10 is 10.867. If you want to run the experiment with *alpha = 0.0* and *gama = 1.0* then you need to use the following commands

```bash
export START_DATA='1 4 0 7 0'
export WEIGHT_VALUES='0.0 1.0 10.867'
export SET_RUNS='600 5'
for i in {1..10}; do sbatch run_EM_verifyta_slurm.sh ; done
```

To use different combination of *alpha* and *gamma* in next experiment, you just need to update *WEIGHT_VALUES* env variable as other variables are already set 

```bash
export WEIGHT_VALUES='0.1 0.9 10.867'
for i in {1..10}; do sbatch run_EM_verifyta_slurm.sh ; done
```

## Plotting cost_discomfort 
first data must be extracted by (on the cluster)

```bash
./extract.sh ./results/2ab018f/
```

Then copy the `DATA` folder to your local machine. 

Pareto frontier can now be plotted from collected data by
```bash
./show_bars.py 0 ./DATA/2ab018f/M1D4H0P7C0.R*
```
where the first parameter indicates distance (0), discomfort (1) or cost (2).

A pareto frontier of comfort/cost can be plotted by
```bash
./pareto.py ./DATA/2ab018f/M1D4H0P7C0.R*
```

## Plotting Th_Ti trajectories and histogram

first data must be extracted by (on the cluster)

```bash
./extract_Th_Ti.sh ./results/2ab018f/
```

Then copy the `ThTe` folder to your local machine. 

Th,Te trajectories for LM and EM are plotted combinely for a specific folder e.g. `M2D4H0P7C0.R300I5.A0.90G0.100000N6.83` as
```bash
./Th_Te_trajectroies.py  ./ThTe/0335c24/M2D4H0P7C0.R300I5.A0.90G0.100000N6.83/
```

Th,Te histograms for LM and EM are plotted combinely for a specific folder e.g. `M2D4H0P7C0.R300I5.A0.90G0.100000N6.83` as
```bash
./Th_Te_histogram.py  ./ThTe/0335c24/M2D4H0P7C0.R300I5.A0.90G0.100000N6.83/
```



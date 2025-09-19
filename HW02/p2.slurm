# !/ usr / bin / env zsh
# SBATCH -- partition = instruction
# SBATCH -- time =00:02:00
# SBATCH -- ntasks =1
# SBATCH -- cpus - per - task =4
# SBATCH -- output = parallel_sums . output
cd $S LURM_S UBMIT _DIR
g ++ -O 2 - std = c ++ 1 7 parallel_sum . cpp -o parallel_sum - pthread
./ parallel_sum

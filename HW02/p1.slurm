# !/ usr / bin / env zsh
# SBATCH -- partition = instruction
# SBATCH -- time =00:02:00
# SBATCH -- ntasks =1
# SBATCH -- cpus - per - task =4
# SBATCH -- output = hello_threads . output
cd $S LURM_S UBMIT _DIR
g ++ -O 2 - std = c ++ 1 7 hello_threads . cpp -o hello_threads - pthread
./ hello_threads

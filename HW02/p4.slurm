# !/ usr / bin / env zsh
# SBATCH -- partition = instruction
# SBATCH -- time =00:02:00
# SBATCH -- ntasks =1
# SBATCH -- cpus - per - task =4
# SBATCH -- output = prod ucer_c onsume r . output
cd $S LURM_S UBMIT _DIR
g ++ -O 2 - std = c ++ 1 7 prod ucer_c onsume r . cpp -o pro ducer_ consum er - pthread
./ pr oducer _consumer

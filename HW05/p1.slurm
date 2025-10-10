#!/usr/bin/env zsh
#SBATCH --partition=instruction
#SBATCH --time=00:05:00
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --gpus-per-task=1
#SBATCH --output=mm_naive.output

module load nvidia/cuda
nvcc mm_naive.cu -o mm_naive
./mm_naive

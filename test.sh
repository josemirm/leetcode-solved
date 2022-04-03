#! /bin/bash
g++ -Wall -Wextra -Wpedantic -fanalyzer -g $1 && gdb -q ./a.out

sudo perf record -g ./build/bench/bench 
sudo perf script > perf.script
./FlameGraph/stackcollapse-perf.pl perf.script | ./FlameGraph/flamegraph.pl > flamegraph.svg
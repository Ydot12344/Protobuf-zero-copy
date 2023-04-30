sudo perf record -g ./build/bench/bench >> report.txt
sudo perf script > perf.script
./third_party/FlameGraph/stackcollapse-perf.pl perf.script | ./third_party/FlameGraph/flamegraph.pl > flamegraph.svg
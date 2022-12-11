cd build/
cmake -DCMAKE_CXX_FLAGS=-pg  -DCMAKE_BUILD_TYPE=Release ..
make
cd ..
sudo ./regenerate_messages.sh
cd build/
cmake -DCMAKE_CXX_FLAGS=-pg  -DCMAKE_BUILD_TYPE=Release ..
make
cd ..
sudo perf record -g ./build/bench/bench >> report.txt
sudo perf script > perf.script
./FlameGraph/stackcollapse-perf.pl perf.script | ./FlameGraph/flamegraph.pl > flamegraph.svg

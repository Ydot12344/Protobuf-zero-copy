cd build/
cmake -DCMAKE_CXX_FLAGS=-pg  -DCMAKE_BUILD_TYPE=Release ..
make protoc  
cd .. 
sudo ./regenerate_messages.sh
cd build/
cmake -DCMAKE_CXX_FLAGS=-pg  -DCMAKE_BUILD_TYPE=Release ..
make bench 
cd ..
sudo perf record -g ./build/bench/bench > report.txt
sudo perf script > perf.script
./third_party/FlameGraph/stackcollapse-perf.pl perf.script | ./third_party/FlameGraph/flamegraph.pl > flamegraph.svg

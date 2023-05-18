cd build/
cmake -DCMAKE_CXX_FLAGS=-pg -DCMAKE_BUILD_TYPE=Release ..
make protoc
cd .. 
sudo ./regenerate_messages.sh
cd build/
cmake -DCMAKE_CXX_FLAGS=-pg  -DCMAKE_BUILD_TYPE=Release ..
make
cd bench
sudo perf record -g ./bench > ../../report.txt
sudo perf script > ../../perf.script
cd ../../
./third_party/FlameGraph/stackcollapse-perf.pl perf.script | ./third_party/FlameGraph/flamegraph.pl > flamegraph.svg

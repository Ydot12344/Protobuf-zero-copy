# Protobuf-zero-copy
### Building & Run benchmarks
OC Linux

Also you need to install Linux perf util
```
apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r`
```

Building and running benchs
```
git clone git@github.com:Ydot12344/Protobuf-zero-copy.git
cd Protobuf-zero-copy/
git submodule update --init --recursive
mkdir build
sudo ./run.sh
```

Text report will be in report.txt and flamegraph in flamegraph.svg.

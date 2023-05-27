# Protobuf-zero-copy

This is a repository with benchmarks for fork of library Protocol Buffers with implementation lazy serialization/deserialization for C++ (attribute [lazy_pack=true])

[Protobuf fork](https://github.com/Ydot12344/protobuf)

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

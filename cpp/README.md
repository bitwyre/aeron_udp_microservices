# aeron_udp_microservices
Aeron UDP microservices

### Build and run Publisher

```
cd build/
cmake ..
make
./pub
```

### Build and run Consumer

```
cd build/
cmake ..
make
./cons
```

# Aeron Latency Test

The mean latency of the Aeron producer to consumer communication using IPC was measured at around 2.4 - 2.5 microseconds, while the mean latency using UDP was measured at around 30-40 microseconds using same machine. 
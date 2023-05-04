# aeron_udp_microservices
Aeron UDP microservices


### Run Java Media Driver Process
```
java -cp external/aeron/aeron-all/build/libs/aeron-all-1.42.0-SNAPSHOT.jar:. RunMediaDriver
```

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


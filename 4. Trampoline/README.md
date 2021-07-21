
<H1> installation guide </H1>

1. download trampoline
```
git clone https://github.com/TrampolineRTOS/trampoline.git
```
2. build viper
```
cd viper
make
```

3. build and install goil
```
cd ..
cd goil/makefile-unix
./build.py
./install.py
```
4. test for Linux
```
cd ..
cd ..
cd examples/posix/periodic
goil --target=posix/linux  --templates=../../../goil/templates/ periodic.oil 
./build.py

export VIPER_PATH=~/trampoline/viper/
./periodic_exe
```

If you completed all the operations correctly you shall see the following output:

**Activation #1

**Activation #2

**Activation #3

Activation #4
Activation #5
Activation #6
Activation #7
Activation #8
Activation #9
Shutdown
Exiting virtual platform.**


```
$ goil --target=posix/darwin  --templates=../../../goil/templates/ periodic.oil
```

```
$ ./make.py
```

```
$ export VIPER_PATH=~/trampoline/viper/
```

```
$ ./periodic_exe
```

```
./make.py clean
```




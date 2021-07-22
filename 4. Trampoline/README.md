
# Installation guide

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

# Trampoline for Posix Targets

POSIX target running Trampoline inside a Unix process. 

To simulate the environment, another process runs ViPER (Virtual Processor EmulatoR). Viper can emulate a timer and send periodically a signal to the Trampoline process. This way, Trampoline get a SystemCounter.

## Building ViPER
on UNIX shell:

    $ cd viper
    $ make
    $ export VIPER_PATH=`pwd`

It is recommended to get the path to ViPER in the environment variables, and define in the ~/.bashrc or ~/.profile the command:

    $ export VIPER_PATH=~/trampoline/viper/

## Run example

Examples are easy to run:
The first time, goil should be called directly. It will generate the appropriate Makefile:

    $ cd examples/posix/periodic
    $ goil --target=posix/linux  --templates=../../../goil/templates/ periodic.oil

Or if you run the example on OSX instead of Linux, 

    $ cd examples/posix/periodic
    $ goil --target=posix/darwin  --templates=../../../goil/templates/ periodic.oil

Then, the makefile is generated, and it will call goil again when the .oil file is updated

    $ ./make.py

Then, run the trampoline binary. This program will start another process to run ViPER silently.

    $ ./periodic_exe

## More
```
./make.py clean
```




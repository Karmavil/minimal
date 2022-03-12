# About

Hi, I am delivering some configurration files with the project but if you're not under linux/gnu and making use vscode I recommend to use the configuration files you usually use, like scons and debug tools.
You will have to twick the folling files: 
* CMakeLists.txt
* godot_project/bin/minimal.gdextension

## Build

You will need the godot-cpp subodule 
```
git submodule update --init --recursive
```

> Note:
If that fails you can try this:
* Run `git restore godot-cpp --recurse-submodules`
* If that failed, clone this repo again but this time including submodules: `git clone --recursive https://github.com/Karmavil/minimal`

then

* Using vscode: 

    * run the task ***Build GodotC++*** (vscode needs SCons, you can use pip3 to add this dependency)
    * run the taks ***Build THIS***

* More options:
    * I will add the Makefile but not today

## Launch

You will need to change the path to your Godot executable so change the path in ***Launch*** task (.vscode/tasks.json).

The same applies to debug (.vscode/launch.json)

## Dependencies

* This minimal project uses `cmake` and `make`. 

* The submodule godot-cpp uses `scons`.
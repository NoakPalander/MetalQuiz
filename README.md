# README

Quiz is a metal quiz developed using C++/Qt, it loads questions from a .json resource file and asks the user to select
the correct answers.
View the docs/html/index.html file for a doxygen documentation.

# Requirements
  - CMake 3.5 or greater
  - Compiler with C++17 support
  - Qt 5.9.9

# Building
### For Linux
Create a 'bin' directory were the executable will be created and change directory into it.
```sh
$ mkdir bin && cd bin
```
Run CMake to generate the build files
```sh
$ cmake ..
```
Compile and link the source code
```sh
$ make
```
Finally you can run the application
```sh
$ ./Quiz
```
### For Windows 10
Make sure you have setup the requirements correctly and all the system environment variables are set
- Set a CMake prefix path to Qt
- Set CMake to "PATH" if it isn't already there
- Install Visual Studio 2017 or greater

Open powershell and direct yourself to the project folder.
Create a 'bin' directory were the executable will be created and change directory into it.
```sh
$ mkdir bin && cd bin
```
Run CMake to generate the build files
```sh
$ cmake ..
```
Compile the source code
- Open the Quiz.sln file in Visual Studio 2017 or greater.
- Configure the language standard by right-clicking on Solution, properties and enable C++17, alternatively "latest".
- Change target from Debug to Release in the top-menubar.
- Select the project and click Build

Move the file and folder contents in the generated Release folder to the "bin" folder created previously

Finally you can run the application by either clicking it, or running it by powershell via
```sh
$ .\Quiz.exe
```

License
----
MIT

# Developers
--- Noak Palander author and developer of the application

--- Nlhomann (https://github.com/nlohmann/json) for the open-source JSON library

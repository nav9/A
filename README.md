# A
A is an AI agent for automating tasks on your computer

# Build on Linux
* Install some dependencies:  
`sudo apt install cmake xorg-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxi-dev libxinerama-dev libxcursor-dev libudev-dev libasound2-dev libpulse-dev`  
`sudo apt install libglfw3-dev libjsoncpp-dev libgl1-mesa-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev`
* Download and install CMake 4 from [here](https://cmake.org/download/).  
* Export the CMake `bin` folder path of CMake in `~/.bashrc` like this `export PATH="$HOME/cmake/bin:$PATH"`.
* Download and extract GLFW source package from [here](https://www.glfw.org/download).  
* Download and install Doxygen (GLFW build process needs it) from [here](https://www.doxygen.nl/download.html).
* Add Doxygen to `~/.bashrc` as `export PATH="$HOME/doxygen-1.13.2/bin:$PATH"`.
* Type `source ~/.bashrc` in the command prompt to make the paths exported effective.  
* Run CMake GUI with the command `cmake-gui` and follow the [build steps](https://www.glfw.org/docs/latest/compile.html) to build GLFW. You may have to manually copy and merge the docs folder from the source folder into the build folder.
* Go to vscode `c_cpp_properties.json` by pressing `Ctrl+Shift+p` and typing `Edit` to find `C/C++ edit configurations (JSON)` and add the following to the include paths `"/usr/include", "/usr/local/include", "/usr/local/include/GLFW/", "/usr/include/x86_64-linux-gnu"`. (the actual include path for glfw3 can be viewed using `pkg-config --cflags glfw3`).
* If there are any changes to files or dependencies in CMakeLists, go to the `build/` folder and run `cmake ..` which will generate a `Make` file.
* Once the `Make` file is generated, run it from the `build/` folder using `make` and run the generated executable using `./A`.


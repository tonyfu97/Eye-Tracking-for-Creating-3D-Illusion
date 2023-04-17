# Eye-Tracking-for-Creating-3D-Illusion
An interactive illusion of depth on a 2D screen by tracking the user's eye position and adjusting the virtual viewing angle of the displayed object.

## Dependencies

This project requires OpenCV version 4.7.0. Please ensure that you have this version installed on your system.

---

### Installation

#### Linux

To install OpenCV 4.7.0 on Linux, follow these steps:

1. Install required packages:

```
sudo apt-get update
sudo apt-get install -y build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```

2. Clone the OpenCV repository and checkout version 4.7.0:

```
git clone https://github.com/opencv/opencv.git
cd opencv
git checkout 4.7.0
```

3. Create a build directory and navigate to it:

```
mkdir build
cd build
```

4. Run CMake to configure the build:

```
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
```

5. Compile OpenCV:

```
make -j$(nproc)
```

6. Install OpenCV:

```
sudo make install
sudo ldconfig
```

---

#### macOS

To install OpenCV 4.7.0 on macOS, follow these steps:

1. Install Homebrew if you haven't already:

```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

2. Update Homebrew:

```
brew update
```

3. Install OpenCV 4.7.0:

```
brew install opencv@4.7.0
```

4. Link the OpenCV version:

```
brew link --force opencv@4.7.0
```

---

#### Windows

For Windows users, you can download the pre-built binaries for OpenCV version 4.7.0 from the official OpenCV website or use package managers like vcpkg or conda to install the required version.

---

### Compile and Run the Application

To compile and run the application, follow these steps:

1. Clone the repository and navigate to the project directory:

```
git clone https://github.com/tonyfu97/Eye-Tracking-for-Creating-3D-Illusion.git
cd Eye-Tracking-for-Creating-3D-Illusion
```

2. Compile the project using the provided Makefile:

```
make
```

3. Run the application:

```
./bin/main
```
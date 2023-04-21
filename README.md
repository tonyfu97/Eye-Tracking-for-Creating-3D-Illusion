# Eye-Tracking-for-Creating-3D-Illusion
An interactive illusion of depth on a 2D screen by tracking the user's eye position and adjusting the virtual viewing angle of the displayed object.

## Dependencies

This project requires OpenCV version 4.7.0. Please ensure that you have this version installed on your system.

### Installation

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

4. Note that you might need to update the include path of your IDE to include
this new directory. For example, OpenCV was installed at `/opt/homebrew/Cellar/opencv/4.7.0_2/include/opencv4` on my MacBook (you can find this path by using the terminal command `locate opencv`).

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
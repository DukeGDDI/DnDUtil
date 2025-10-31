# DnDUtil
A command line DnD utility for managing your character.  Replaces the need for a character sheet.

# Depenencies
This projected relies on Googles Unit Test framework.  I am using the Debian/Unix version to build and test
this library.


Here is how to install and build the google tests.
```
sudo apt update
sudo apt install libgtest-dev cmake build-essential

# Configure & build *in your home directory*
cmake -S /usr/src/googletest -B "$HOME/.local/gtest-build"
cmake --build "$HOME/.local/gtest-build"

```

Build and run tests by calling `make` at the root of this project.

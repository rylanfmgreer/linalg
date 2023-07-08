# linalg

working build command on my machine (this is mostly for my reference)
g++  -stdlib=libc++ -std=c++17 -g tests.cpp  $(find src -type f -iregex ".*\.cpp") -o a
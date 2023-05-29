# linalg

to compile, i call the following command:
g++ -std=c++17 -stdlib=libc++  -g tests.cpp  $(find src -type f -iregex ".*\.cpp") -o a
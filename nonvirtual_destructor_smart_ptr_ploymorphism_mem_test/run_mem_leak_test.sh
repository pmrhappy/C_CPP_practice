g++ main.cpp
valgrind --leak-check=full --show-leak-kinds=all ./a.out

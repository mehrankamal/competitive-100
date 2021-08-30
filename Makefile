CC = g++
CPPFLAGS = -DLOCAL --std=c++17 -Werror -Wall
FILE = $(filter-out $@, $(MAKECMDGOALS))

main: $(FILE)
	$(CC) $(CPPFLAGS) -o main $(FILE)

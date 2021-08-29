CC = g++
CPPFLAGS = -DLOCAL -Wall -Werror -Wextra --std=c++14 -O2
FILE = $(filter-out $@, $(MAKECMDGOALS))

main: $(FILE)
	$(CC) $(CPPFLAGS) -o main $(FILE)

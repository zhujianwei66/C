EXEC = main
CC = gcc
OBJ = main.o link.o
$(EXEC):$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $< -o $@
clean:
	rm $(OBJ) $(EXEC)

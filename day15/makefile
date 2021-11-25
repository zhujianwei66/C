EXEC=main
CC = gcc
OBJ = 00_code.o
$(EXEC):$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $< -o $@
clean:
	rm $(OBJ) $(EXEC)

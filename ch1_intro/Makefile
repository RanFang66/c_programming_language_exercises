# Makefile

SOURCE = $(wildcard pra1_*.c)
TARGET = $(basename $(SOURCE))
OBJ = $(foreach n, $(TARGET), $(n).o)

.PHONY : all clean

all : $(TARGET)
pra1_1 : pra1_1.o
	gcc -o $@ $^	

clean : 
	rm -rf $(OBJ) $(TARGET)




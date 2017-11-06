CC = g++
CCFLAGS= -Wall -pedantic -std=c++11
EXTC = cpp
EXTH = h
EXECUTABLE = TP6-DM_CANO_COUPPOUSSAMY.exe

SRC = $(wildcard *.$(EXTC))
HDR = $(wildcard *.$(EXTH))
OBJ = $(SRC:.$(EXTC)=.o)

.PHONY:all

all: $(EXECUTABLE)
$(EXECUTABLE):$(OBJ)
	@$(CC) -o $@ $^
%.o:%.$(EXTC) %.$(EXTH)
	@$(CC) $(CCFLAGS) -o $@ -c $<
clean:
	@rm -rf *.o
	@rm -f $(EXECUTABLE)
	@echo "Clean ok"

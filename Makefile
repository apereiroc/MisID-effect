CC         = g++
src        = $(wildcard src/*.cpp)
obj        = $(src:.cpp=.o)
CPPFLAGS   = -I./include
#LDFLAGS = -lGL -lglut -lpng -lz -lm

myprogram: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) $(CPPFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprogram
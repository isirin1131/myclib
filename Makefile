CFLAGS=-g -Isrc -Wall

SOURCES=$(wildcard src/**/*.c src/*.c)
TEST_SRC=$(wildcard tests/**/*.c tests/*.c)

OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
TESTS=$(patsubst %.c,%,$(TEST_SRC))

all: $(TESTS)

$(TESTS): %: %.c $(OBJECTS)
	cc $(CFLAGS) $< $(OBJECTS) -o $@

$(OBJECTS): %.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TESTS)

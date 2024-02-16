#flags for compiler
CC=gcc -std=c11 -D_GNU_SOURCE

#flags for correct lib compilation
TST_LIBS=-lcheck -lm -lpthread

#enable code coverage analysis
GCOV_LIBS=--coverage

#mean program will be build in the current directory
BUILD_PATH=./

#probably should be replaced with *.c
SOURCES=s21_string.c

#our header
H=s21_string.h

#module or object file that is created from the object files
LIBO=s21_string.o

#represent final library file that is created from the object
LIBA=s21_string.a

#EXE file to run with
EXE=test.out

#represent current Operation System of computer
OS:=$(shell uname -s)

ifeq ($(OS),Linux)
		CC+=-D LINUX_OS
	else
		ifeq ($(OS),Darwin)
			CC+=-D MAC_OS
		else
		CC+=-D LINUX_OS
		endif
endif

all: s21_string.a test gcov_report

run: s21_string.
	$(CC)

clean:
	rm -rf *.a && rm -rf *.o
	rm -rf *.info && rm -rf *.gcda && rm -rf *.gcno &&  rm -rf *.gcov
	rm -rf report/ && rm -rf *.out

test: s21_string.a
	$(CC) test.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)

rebuild: clean all

s21_string.a: clean
	$(CC) -c $(SOURCES) -o $(BUILD_PATH)$(LIBO)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

gcov_report: s21_string.a
	$(CC) $(GCOV_LIBS) test.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov -t "test" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/

check:
	@echo
	@echo ===CPPCHECK===
	@echo
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	@echo
	@echo ===STYLE TEST===
	@echo
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	@echo
	@echo ===LEAKS TEST===
	@echo
	CK_FORK=no leaks -atExit -- $(BUILD_PATH)$(EXE)

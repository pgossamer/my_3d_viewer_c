CC=gcc
CFLAGS = -c -Wall -Wextra -Werror -std=c11
LDFLAGS = -Wall -Wextra -Werror -std=c11

PATH := $(PATH):$(HOME)/homebrew/bin:$(HOME)/.brew/bin
BD = ../build/
APP = $(BD)3DViewer_v1.0.app

GCOV = --coverage

all: clean install

build: copy_pro
	cd $(BD); qmake 3DViewer_v1.0.pro
	make -C $(BD)

copy_pro: 
	cp project/3DViewer_v1.0.pro $(BD)
	cp project/*.c project/*.h project/*.cpp project/*.ui project/*.qrc project/*.png project/*.glsl  $(BD)
	cp -r images/ $(BD)

install: build
	@mkdir $(HOME)/Desktop/3DViewer_v1.0/
	@cp -rf $(APP) $(HOME)/Desktop/3DViewer_v1.0/
	make clean

uninstall:
	@rm -rf $(HOME)/Desktop/3DViewer_v1.0/

dvi: 
	@open documentation.html

dist:
	rm -rf $(HOME)/Desktop/Archive_3DViewer.0.tar.gz
	@cd ../; tar -czvf Archive_3DViewer.0.tar.gz *
	cd ../;mv Archive_3DViewer.0.tar.gz $(HOME)/Desktop/


tests:
	$(CC) $(FLAGS) viever_test.c project/parser.c project/affine_transformations.c -o tests -lcheck
	./tests

check: tests
	@cppcheck --enable=all --suppress=missingIncludeSystem project/parser.c project/affine_transformations.c viever_test.c
	@CK_FORK=no leaks --atExit -- ./tests

gcov_report: clean lcov tests 
	mkdir report
	$(CC) $(CFLAGS) $(GCOV) viever_test.c project/parser.c project/affine_transformations.c
	$(CC) -o $@ $(LFLAGS) $(GCOV) viever_test.o parser.o affine_transformations.o -lcheck 
	./$@
	gcov viever_test.c
	$(shell PATH=$(PATH) which lcov) -t 3DViewer -o 3DViewer.info -c -d . --no-external
	$(shell PATH=$(PATH) which genhtml) -o report 3DViewer.info
	open ./report/index.html

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif

clean:
	@rm -rf *.o *.a *.out *.info *.gcno *.gcda *.gcov tests s21_test
	@rm -rf ./test && rm -rf ./gcov_report
	@rm -rf ./report
	@rm -rf ./$(BD)*

rebuild: clean all

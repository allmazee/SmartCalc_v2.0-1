.PHONY: all clean tests install uninstall dvi dist gcov_report

CXX=g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17 -pthread
GCOVFLAGS=-fprofile-arcs -ftest-coverage
TEST_LIBS = -lgtest -lgtest_main
QMAKE = qmake6
CPP_FILES = Models/calculator_model.cpp Controllers/calculator_controller.cpp
HEADERS = Models/calculator_model.h Controllers/calculator_controller.h
TEST_FILE = Tests/tests.cpp
INST_DIR = build
DIST_DIR = dist
EXE_DIR = Views
TEST_DIR = Tests
OS = $(shell uname)

ifeq ($(OS), Darwin)
	EXE_FILE=SmartCalc_2_0.app
else
	EXE_FILE=SmartCalc_2_0
endif

all: style install tests gcov_report dvi dist

install: uninstall clean
	mkdir -p $(INST_DIR)
	cd $(EXE_DIR) && \
	$(QMAKE) && \
	make && \
	mv $(EXE_FILE) ../$(INST_DIR)
	open $(INST_DIR)/./$(EXE_FILE)

uninstall: 
	rm -rf $(INST_DIR)

clean:
	rm -rf $(TEST_DIR)/*.out $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno
	rm -rf *.gcda *.gcno coverage_report *.info
	# rm -rf *.out
	# rm -rf *.h.gch
	rm -rf $(DIST_DIR).tar
	rm -rf $(EXE_DIR)/$(EXE_FILE) $(EXE_DIR)/.qmake.stash $(EXE_DIR)/moc_* $(EXE_DIR)/ui_*.h $(EXE_DIR)/*.o $(EXE_DIR)/Makefile

dvi:
	open dvi/dvi.html

dist:
	mkdir -p $(DIST_DIR)
	cp build/$(EXE_FILE) $(DIST_DIR) && cp -r dvi $(DIST_DIR)
	tar --totals -cvf $(DIST_DIR).tar $(DIST_DIR)
	rm -rf $(DIST_DIR)

tests: clean
	$(CXX) $(CPP_FILES) $(TEST_FILE) $(CXXFLAGS) -o $(TEST_DIR)/tests.out $(TEST_LIBS) $(GCOVFLAGS)
	./$(TEST_DIR)/tests.out

gcov_report: tests
	# cd $(TEST_DIR)
	gcov $(HEADERS)
	lcov --capture --directory . --output-file coverage.info --exclude '/usr/include/*'
	genhtml coverage.info --output-directory coverage_report 
	open coverage_report/index.html
	cd $(TEST_DIR) && \
	rm -f *.gcno *.gcda *.info tests.out *.gcov

style : 
	clang-format --verbose -style=Google -n Tests/*.cpp
	clang-format --verbose -style=Google -n Models/*.cpp
	clang-format --verbose -style=Google -n Models/*.h
	clang-format --verbose -style=Google -n Controllers/*.cpp
	clang-format --verbose -style=Google -n Controllers/*.h
	clang-format --verbose -style=Google -n Views/mainwindow.cpp Views/creditwindow.cpp Views/plotwindow.cpp Views/qcustomplot.cpp Views/main.cpp
	clang-format --verbose -style=Google -n Views/mainwindow.h Views/creditwindow.h Views/plotwindow.h Views/qcustomplot.h

lint:
	clang-format --verbose -style=Google -i Tests/*.cpp
	clang-format --verbose -style=Google -i Models/*.cpp
	clang-format --verbose -style=Google -i Models/*.h
	clang-format --verbose -style=Google -i Controllers/*.cpp
	clang-format --verbose -style=Google -i Controllers/*.h
	clang-format --verbose -style=Google -i Views/*.cpp
	clang-format --verbose -style=Google -i Views/*.h

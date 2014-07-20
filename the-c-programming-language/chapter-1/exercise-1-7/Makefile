CC     = gcc
CFLAGS = -Wall -Werror
OUT_DIR=bin
BUILD_DIR=build
TEST_BUILD_DIR=test_build
SRC_DIR=src
TEST_SRC_DIR=tests
MAIN=$(SRC_DIR)/print_eof.c
EXE=$(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%, $(MAIN))
SRC= $(wildcard $(SRC_DIR)/*.c)
OBJ= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
COV_OBJ= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.cov.o, $(filter-out $(MAIN), $(SRC)))
COVERAGE= $(patsubst $(TEST_BUILD_DIR)/%_tests, %.c.gcov, $(TESTS))
TESTS= $(patsubst $(SRC_DIR)/%.c, $(TEST_BUILD_DIR)/%_tests, $(filter-out $(MAIN), $(SRC)))
TEST_SRC= $(patsubst $(SRC_DIR)/%.c, $(TEST_SRC_DIR)/%_tests.c, $(filter-out $(MAIN), $(SRC)))
TEST_OBJ= $(patsubst $(TEST_SRC_DIR)/%.c, $(TEST_BUILD_DIR)/%.o, $(TEST_SRC))

#profile
#integration_tests - Done
#compile
#quick_check - Done: Use quick check in unit tests
#coverage - Done
#unit_tests - Done
# This will run all tests as long as there is a test file for every src file not in the exclude list

.PHONY: all_tests all

all: $(EXE) all_tests
	cucumber 

$(EXE): $(MAIN)
	$(CC) $(CFLAGS) $(SRC) -o $@

all_tests: $(COVERAGE)

$(COVERAGE): %.c.gcov : $(SRC_DIR)/%.c $(TESTS)
	@gcov --object-directory=$(TEST_BUILD_DIR) -abc $< | grep -ce ':[0-9][0-9].[0-9][0-9]%' | grep "0"
	@mv $@ coverage/$@

$(TESTS): $(TEST_BUILD_DIR)/%_tests : $(BUILD_DIR)/%.o $(TEST_BUILD_DIR)/%_tests.o
	$(CC) -fprofile-arcs -ftest-coverage $(CFLAGS) -o $@ $^ `pkg-config --cflags --libs check`
	@$@

$(TEST_OBJ): $(TEST_BUILD_DIR)/%.o : $(TEST_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ): $(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -fprofile-arcs -ftest-coverage $(CFLAGS) -c -o $@ $<

clean:
	rm -f build/* test_build/* bin/* coverage/*

init:
	mkdir src tests test_build build features coverage

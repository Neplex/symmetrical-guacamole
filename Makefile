
## TDM number
TDM_NUMBER := 09


TEST_NAME :=  ok export_eps shape factory_1 factory_2 read read_export

SHAPE_EXAMPLE_NUMBERS := 1 2 3 4 5

SHELL := bash

##
## HELP
##
.PHONY : help

help :
	@echo "Available:"
	@echo "- ok => to test dynamic library"
	@echo "- K => compilation (should not produce any error nor warning)"
	@echo "- TS MS  => test (T output and M memory) of test_shape"
	@echo "- TF1 TF2 MF1 MF2  => test (T output and M memory) of test_factory_1 test_factory_2"
	@echo "- TR1 .. TR5  => test (output) of test_read on fig xx .shape"
	@echo "- MR1 .. MR5  => test memory of test_read on fig xx .shape"
	@echo "- TE1 .. TE5  => test (output) of test_export on fig xx .shape"
	@echo "- ME1 .. ME5  => test memory of test_export on fig xx .shape"
	@echo "- T    => all test on output"
	@echo "- M    => all test on memory"
	@echo "- pack => produce the tgz archive"

##
## COMPILATION
##  automatic of C++ ansi (98) => .hpp .cpp files
##
.PHONY : K

.PHONY : ok make all clean shape


MODULES_CPP = factory_shape.o export_eps.o shape.o

MODULES_SHAPE = shape_circle shape_square shape_triangle shape_scale shape_translate shape_rotate shape_intersect shape_union shape_difference shape_minus

MODULES_SHAPE_SO = $(MODULES_SHAPE:%=lib%.so)
MODULES_SHAPE_O = $(MODULES_SHAPE:%=%.o)

##
##  COMPILATION PARAMETERS
##


# Compilteurs
CC := gcc
CCPP := g++


# options de compilation

## Comme il s'agit de code pour un cours, il y a souvent des variables inutiles
CPP_FLAG_OFF_UNUSED := -Wno-unused-variable -Wno-unused-parameter

CPP_FLAGS := -std=c++98 -Wall -Wextra -pedantic -ggdb $(CPP_FLAG_OFF_UNUSED)


#
# COMPILATION RULES
#

# remove implicit rules
%.o : %.c
%.o : %.cpp
% : %.c
% : %.cpp


%.o : %.cpp $(wildcard *.hpp) $(MAKEFILE_LIST)
	$(CCPP) -c $(CPP_FLAGS) -o $@ $<
# remove symbol create_instance from .o
	strip --strip-symbol=create_instance $@

all : $(MODULES_CPP) $(MODULES_SHAPE_SO)

lib%.so : %.cpp $(wildcard *.hpp) $(MODULES_CPP)
	g++ -shared -Wl,-soname,libmean.so.1 -o lib$*.so $*.cpp -fPIC $(CPP_FLAGS)

test_shape : test_shape.cpp $(wildcard *.hpp) $(MODULES_CPP) $(MAKEFILE_LIST) $(MODULES_SHAPE_O)
	$(CCPP) -Wl,--no-as-needed,-ldl $(CPP_FLAGS) -o $@ $(MODULES_CPP)  $(MODULES_SHAPE_O) $<

test_% : test_%.cpp $(wildcard *.hpp) $(MODULES_CPP) $(MAKEFILE_LIST) $(MODULES_SHAPE_SO)
	$(CCPP) -Wl,--no-as-needed,-ldl $(CPP_FLAGS) -o $@ $(MODULES_CPP) $<

# compile all
K : $(TEST_NAME:%=test_%)


##
## TEST
##
.PHONY : ok T M

VALGRIND := valgrind --leak-check=full --show-leak-kinds=all >/dev/null

OUTPUT_SUFFIX := _out.txt
OUTPUT_EXPECTED_SUFFIX := _out_expected.txt
OUTPUT_EXPECTED_SUFFIX_EPS := _out_expected.eps


TS : test_shape
	./test_shape > test_shape$(OUTPUT_SUFFIX)
	diff -Z test_shape$(OUTPUT_SUFFIX) test_shape$(OUTPUT_EXPECTED_SUFFIX)

MS : test_shape
	$(VALGRIND) ./test_shape

TF% : test_factory_%
	./test_factory_$*

MF% : test_factory_%
	$(VALGRIND) ./test_factory_$*

TR% : test_read
	./test_read $*

MR% : test_read
	$(VALGRIND) ./test_read $*

TE% : test_read_export
	./test_read_export $*
	diff -Z  fig$*.eps fig$*.$(OUTPUT_EXPECTED_SUFFIX_EPS)

ME% : test_read_export
	$(VALGRIND) ./test_read_export $*

ok : test_ok libok.so
	./test_ok

shape : test_shape
	./test_shape

T : ok TF1 TF2 $(SHAPE_EXAMPLE_NUMBERS:%=TR%) $(SHAPE_EXAMPLE_NUMBERS:%=TE%)

M : ok MF1 MF2 $(SHAPE_EXAMPLE_NUMBERS:%=MR%) $(SHAPE_EXAMPLE_NUMBERS:%=ME%)


##
## CLEAN
##
.PHONY : clean

clean:
	rm -f *.o $(TEST_NAME:%=test_%) $(TEST_NAME:%=test_%$(OUTPUT_SUFFIX))


##
## PRODUCE THE ARCHIVE (to upload on Celene)
##
.PHONY : pack


#
# Pour faire l'archive de remise
#
TGZ_INCLUDED_FILES := *.cpp *.hpp ?akefile cr.pdf
TDM_DIR := TDM_$(TDM_NUMBER)
TGZ_FILE := $(TDM_DIR)/TDM_$(TDM_NUMBER)

pack :
	[ -e cr.pdf ] || echo > cr.pdf
	cd .. ; tar czf $(TGZ_FILE).tgz $(TGZ_INCLUDED_FILES:%=$(TDM_DIR)/%)

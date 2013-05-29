#CRAZY=-save-temps -integrated-as -v
#DIAG=-fshow-column -fshow-source-location -fcaret-diagnostics -fdiagnostics-fixit-info -fdiagnostics-parseable-fixits -fdiagnostics-print-source-range-info -fprint-source-range-info -fdiagnostics-show-option -fmessage-length
LLVMWARN=-Weverything -Wno-c++11-extensions -pedantic
GCCWARN=-Wall
WARN=$(LLVMWARN)
GCC=clang++

PROJECT=SmartPtr

SOURCES=main.cpp 
DEPS=$(wildcard *)

$(PROJECT): $(SOURCES) $(DEPS)
	$(GCC) $(WARN) $(CRAZY) $(DIAG) -g -o $@ $(SOURCES)

clean:
	git clean -X -d -f

test: $(PROJECT)
	bash -c "time ./$< | tail"

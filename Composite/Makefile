#CRAZY=-save-temps -integrated-as -v
DIAG=-fshow-column -fshow-source-location -fcaret-diagnostics -fdiagnostics-fixit-info -fdiagnostics-parseable-fixits -fdiagnostics-print-source-range-info -fprint-source-range-info -fdiagnostics-show-option -fmessage-length
WARN=-Weverything -Wno-c++11-extensions -pedantic

PROJECT=Composite

SOURCES=main.cpp SceneBuilder.cpp
DEPS=$(wildcard *.cpp) $(wildcard *.hpp) Makefile

$(PROJECT): $(DEPS)
	clang++ $(WARN) $(CRAZY) $(DIAG) -g -o $@ $(SOURCES)

clean:
	git clean -X -d -f

test: $(PROJECT)
	bash -c "time ./$< | tail"

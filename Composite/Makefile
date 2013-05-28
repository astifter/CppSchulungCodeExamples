#CRAZY=-save-temps -integrated-as -v
DIAG=-fshow-column -fshow-source-location -fcaret-diagnostics -fdiagnostics-fixit-info -fdiagnostics-parseable-fixits -fdiagnostics-print-source-range-info -fprint-source-range-info -fdiagnostics-show-option -fmessage-length

PROJECT=Composite

SOURCES=main.cpp 
DEPS=$(wildcard *)

$(PROJECT): $(SOURCES) $(DEPS)
	clang++ $(CRAZY) $(DIAG) -g -o $@ $(SOURCES)

clean:
	git clean -X -d -f

test: $(PROJECT)
	bash -c "time ./$< | tail"

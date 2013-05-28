#CRAZY=-save-temps -integrated-as -v
DIAG=-fshow-column -fshow-source-location -fcaret-diagnostics -fdiagnostics-fixit-info -fdiagnostics-parseable-fixits -fdiagnostics-print-source-range-info -fprint-source-range-info -fdiagnostics-show-option -fmessage-length

SOURCES=inheritance.cpp Pet.cpp Dog.cpp Cat.cpp

inheritance: $(SOURCES) Makefile
	clang++ $(CRAZY) $(DIAG) -g -o $@ $(SOURCES)

inheritancegcc: $(SOURCES) Makefile
	g++ -g -o $@ $(SOURCES)

gcc: inheritancegcc

llvm: inheritance

clean:
	git clean -X -d -f

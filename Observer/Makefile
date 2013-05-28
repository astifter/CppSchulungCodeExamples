#CRAZY=-save-temps -integrated-as -v
DIAG=-fshow-column -fshow-source-location -fcaret-diagnostics -fdiagnostics-fixit-info -fdiagnostics-parseable-fixits -fdiagnostics-print-source-range-info -fprint-source-range-info -fdiagnostics-show-option -fmessage-length

SOURCES=main.cpp Generator.cpp

Observer: $(SOURCES) Makefile
	clang++ $(CRAZY) $(DIAG) -g -o $@ $(SOURCES)

Observergcc: $(SOURCES) Makefile
	g++ -g -o $@ $(SOURCES)

gcc: Observergcc

llvm: Observer

clean:
	git clean -X -d -f

test: Observer
	bash -c "time ./$< > /dev/null"
	bash -c "time ./$< -f > /dev/null"

testgcc: Observergcc
	bash -c "time ./$< > /dev/null"
	bash -c "time ./$< -f > /dev/null"

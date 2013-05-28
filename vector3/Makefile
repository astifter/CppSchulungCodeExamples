#CRAZY=-save-temps -integrated-as -v
DIAG=-fshow-column -fshow-source-location -fcaret-diagnostics -fdiagnostics-fixit-info -fdiagnostics-parseable-fixits -fdiagnostics-print-source-range-info -fprint-source-range-info -fdiagnostics-show-option -fmessage-length

vector3: vector3.cpp Makefile
	clang++ $(CRAZY) $(DIAG) -g -o $@ $<

vector3gcc: vector3.cpp Makefile
	g++ -g -o $@ $<

gcc: vector3gcc

llvm: vector3

clean:
	git clean -X -d -f

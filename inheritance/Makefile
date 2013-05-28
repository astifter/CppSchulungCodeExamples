#CRAZY=-save-temps -integrated-as -v
DIAG=-fshow-column -fshow-source-location -fcaret-diagnostics -fdiagnostics-fixit-info -fdiagnostics-parseable-fixits -fdiagnostics-print-source-range-info -fprint-source-range-info -fdiagnostics-show-option -fmessage-length

inheritance: inheritance.cpp Makefile
	clang++ $(CRAZY) $(DIAG) -g -o $@ $<

inheritancegcc: inheritance.cpp Makefile
	g++ -g -o $@ $<

gcc: inheritancegcc

llvm: inheritance

clean:
	git clean -X -d -f

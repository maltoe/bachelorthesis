TEMPORARIES=*aux *toc *log *blg *bbl *out *lol *lot *lof parts/*aux
ARTIFACTS=*pdf *dvi *ps

all: clean compile removetemporaries

compile:
	latex thesis.tex
#	bibtex8 thesis
	latex thesis.tex
	latex thesis.tex

pdf: compile removetemporaries
	dvips thesis.dvi
	ps2pdf thesis.ps
	rm -f *dvi *ps

clean:
	rm -f $(TEMPORARIES) $(ARTIFACTS)
	
removetemporaries:
	rm -f $(TEMPORARIES)

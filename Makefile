TEMPORARIES=*aux *toc *log *blg *bbl *out *lol *lot *lof parts/*aux parts/*log
ARTIFACTS=*pdf *dvi *ps
LATEX_OPTS=-interaction=nonstopmode

all: clean compile removetemporaries

compile:
	latex ${LATEX_OPTS} thesis.tex
#	bibtex8 thesis
	latex ${LATEX_OPTS} thesis.tex
	latex ${LATEX_OPTS} thesis.tex

pdf: compile removetemporaries
	dvips thesis.dvi
	ps2pdf thesis.ps
	rm -f *dvi *ps

clean:
	rm -f $(TEMPORARIES) $(ARTIFACTS)
	
removetemporaries:
	rm -f $(TEMPORARIES)

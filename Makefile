all: clean compile removetemporaries

compile:
	latex bericht.tex
	bibtex8 bericht
	latex bericht.tex
	latex bericht.tex

pdf: compile
	dvips bericht.dvi
	ps2pdf bericht.ps

clean:
	rm -f *pdf *dvi *aux *toc *log *blg *bbl *ps
	
removetemporaries:
	rm -f *aux *toc *log *blg *bbl

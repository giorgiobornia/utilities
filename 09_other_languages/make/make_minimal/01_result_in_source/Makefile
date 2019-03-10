#------------CUSTOMIZABLE MAKEFILE---------------#
#DEFINITION OF VARIABLES
#folders
SRCDIR:= src
BINDIR:= bin
INCLUDEDIR:= include
#file extensions (please use only one type!)
SRCEXT:= c
OBJEXT:= o
HDREXT:= h
#file names
SOURCES := $(wildcard $(SRCDIR)/*.$(SRCEXT) ) 
OBJECTS := $(patsubst %.$(SRCEXT),%.$(OBJEXT), $(SOURCES) )
HEADERS := $(wildcard $INCLUDEDIR)/*.$(HDREXT) )
BINNAME:= ese
#compiler and compiler-dependent options
COMPILER:= gcc
LINKER:= gcc
RETURNS:= -o
COMPILES:= -c
SEARCHES_FOR_INCLUDE_IN:= -I
OPTFLAGS = -Wall
#cleaning and his options
LETSCLEAN:= rm
FORCEDLY:= -f

#dependencies
PERL:= perl
DEPMAKER = make_dependencies.pl



#LINKING RULE AMONG OBJECTS AND LIBRARIES
$(BINNAME) : $(OBJECTS)
	$(LINKER) $(OBJECTS) $(RETURNS) $(BINDIR)/$(BINNAME)


#COMPILING RULE
%.$(OBJEXT) : %.$(SRCEXT)
	$(COMPILER) $(OPTFLAGS) $(SEARCHES_FOR_INCLUDE_IN)$(INCLUDEDIR) $(COMPILES) $< $(RETURNS) $@

#HEADER RULE
include depend

depend:
	$(PERL) $(DEPMAKER) -I$(INCLUDEDIR) "-S\$$(OBJEXT)" $(SOURCES) > depend
	@echo "Updated depend"


#CLEANING OUTPUTS
.PHONY: clean

clean :
	$(LETSCLEAN) $(FORCEDLY) $(BINDIR)/$(BINNAME)
	$(LETSCLEAN) $(FORCEDLY) $(OBJECTS)
	$(LETSCLEAN) $(FORCEDLY) *~ $(SRCDIR)/*~ $(INCLUDEDIR)/*~ 



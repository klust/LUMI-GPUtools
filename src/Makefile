EXECUTABLES=select_gpu
BUILDBINDIR=../bin

SHELL=bash

all : $(EXECUTABLES:%=$(BUILDBINDIR)/%)

$(BUILDBINDIR)/select_gpu : select_gpu.c Makefile
	mkdir -p $(BUILDBINDIR)
	gcc -O2 $< -o $@

clean :
	-/bin/rm -f $(EXECUTABLES:%=.$(BUILDBINDIR)/%)

test : test_select_gpu

test_select_gpu : $(BUILDBINDIR)/select_gpu
	@echo "Testing select_gpu..."
	@buildbindir=$(BUILDBINDIR) ; \
	if [ "$$(ROCR_VISIBLE_DEVICES= SLURM_LOCALID=200 $${buildbindir}/select_gpu env | grep ROCR_VISIBLE_DEVICES)" = "ROCR_VISIBLE_DEVICES=200" ] ; \
	    then echo "Test of select_gpu succeeded" ; \
	    else echo "Test of select_gpu failed" ; exit 1 ; \
	fi




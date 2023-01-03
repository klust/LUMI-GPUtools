# Use with -rR if you want to make sure that CC and CFLAGS are taken from the
# environment if defined, or use the Makefile in the parent directory.
EXECUTABLES = select_gpu
BUILDBINDIR = ../bin

CC ?= gcc
CFLAGS ?= -O3

SHELL=bash

# The following will actually avoid using aliases for the respective commands,
# even if they are defined.
MKDIR = $(shell which mkdir || echo "mkdir")
RM = $(shell which rm || echo "rm")

.SUFFIXES:

build : $(EXECUTABLES:%=$(BUILDBINDIR)/%)

$(BUILDBINDIR)/select_gpu : select_gpu.c Makefile
	$(MKDIR) -p $(BUILDBINDIR)
	$(CC) $(CFLAGS) $< -o $@

clean :
	-$(RM) -f $(EXECUTABLES:%=$(BUILDBINDIR)/%)

test : test_select_gpu

test_select_gpu : $(BUILDBINDIR)/select_gpu
	@echo "Testing select_gpu..."
	@buildbindir=$(BUILDBINDIR) ; \
	if [ "$$(ROCR_VISIBLE_DEVICES= SLURM_LOCALID=200 $${buildbindir}/select_gpu env | grep ROCR_VISIBLE_DEVICES)" = "ROCR_VISIBLE_DEVICES=200" ] ; \
	    then echo "Test of select_gpu succeeded" ; \
	    else echo "Test of select_gpu failed" ; exit 1 ; \
	fi

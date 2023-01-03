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
	@# Test 1
	@buildbindir=$(BUILDBINDIR) ; \
	if [ "$$(ROCR_VISIBLE_DEVICES= SLURM_LOCALID=1 $${buildbindir}/select_gpu env | grep ROCR_VISIBLE_DEVICES)" = "ROCR_VISIBLE_DEVICES=1" ] ; \
	    then echo "Test 1 of select_gpu succeeded" ; \
	    else echo "Test 1 of select_gpu failed" ; exit 1 ; \
	fi
	@# Test 2: Check if ROCR_VISIBLE_DEVICES is overwritten with the correct value.
	@buildbindir=$(BUILDBINDIR) ; \
	if [ "$$(ROCR_VISIBLE_DEVICES=2 SLURM_LOCALID=1 $${buildbindir}/select_gpu env | grep ROCR_VISIBLE_DEVICES)" = "ROCR_VISIBLE_DEVICES=1" ] ; \
	    then echo "Test 2 of select_gpu succeeded" ; \
	    else echo "Test 2 of select_gpu failed" ; exit 1 ; \
	fi
	@# Test 3: We should get an error return in this case as SLURM_LOCALID is empty.
	@buildbindir=$(BUILDBINDIR) ; \
	SLURM_LOCALID= $${buildbindir}/select_gpu env >& /dev/null ; \
	if [ $$? -ne 0 ] ; \
		then echo "Test 3 of select_gpu succeeded" ;  \
		else echo "Test 3 of select_gpu failed" ; exit 1 ; \
	fi
	@# Test 4: We should get an error return in this case as SLURM_LOCALID is a negative number.
	@buildbindir=$(BUILDBINDIR) ; \
	SLURM_LOCALID=-1 $${buildbindir}/select_gpu env >& /dev/null ; \
	if [ $$? -ne 0 ] ; \
		then echo "Test 4 of select_gpu succeeded" ;  \
		else echo "Test 4 of select_gpu failed" ; exit 1 ; \
	fi
	@# Test 5: We should get an error return in this case as SLURM_LOCALID is a not a number.
	@buildbindir=$(BUILDBINDIR) ; \
	SLURM_LOCALID=1a $${buildbindir}/select_gpu env >& /dev/null ; \
	if [ $$? -ne 0 ] ; \
		then echo "Test 5 of select_gpu succeeded" ;  \
		else echo "Test 5 of select_gpu failed" ; exit 1 ; \
	fi
	@# Test 6: Check if select_gpu fails in the expected way when no arguments are given.
	@buildbindir=$(BUILDBINDIR) ; \
	$${buildbindir}/select_gpu |& grep -q file-to-exec ; \
	if [ $$? -eq 0 ] ; \
		then echo "Test 6 of select_gpu succeeded" ;  \
		else echo "Test 6 of select_gpu failed" ; exit 1 ; \
	fi


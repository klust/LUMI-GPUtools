PREFIX=./INSTALL

# Disable built-in rules and variables.
# This only takes effect for submakes, but it is enough to let 
# the build process pick up the environment variables set by EasyBuild
# should we want this.
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

SHELL=bash
MKDIR = $(shell which mkdir || echo "mkdir")
CP = $(shell which cp || echo "cp")

build :
	$(MAKE) -C src build
	
test :
	$(MAKE) -C src test
	
install : build
	@$(MKDIR) -p $(PREFIX)/share/licenses
	@$(CP) -rf bin $(PREFIX)
	@$(CP) -rf man $(PREFIX)/share
	@$(CP) -f LICENSE $(PREFIX)/share/licenses/LICENSE.lumi-GPUtools
	
clean :
	$(MAKE) -C src clean

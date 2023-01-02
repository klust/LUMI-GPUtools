PREFIX=./INSTALL

build :
	$(MAKE) -C src build
	
test :
	$(MAKE) -C src test
	
install :
	@mkdir -p $(PREFIX)/share/licenses
	@cp -rf bin $(PREFIX)
	@cp -rf man $(PREFIX)/share
	@cp -f LICENSE $(PREFIX)/share/licenses/LICENSE.lumi-GPUtools
	
clean :
	$(MAKE) -C src clean

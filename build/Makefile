TARGET := $(shell uname)

all: HxCFloppyEmulator_cmdline

libhxcadaptor:
	$(MAKE) -C ../libhxcadaptor/trunk/build/

libhxcfe: libhxcadaptor
	$(MAKE) -C ../libhxcfe/trunk/build/

libusbhxcfe: libhxcadaptor libhxcfe
	$(MAKE) -C ../libusbhxcfe/trunk/build/

HxCFloppyEmulator_cmdline: libusbhxcfe
	$(MAKE) -C ../HxCFloppyEmulator_cmdline/trunk/build/

mrproper:
	$(MAKE) -C ../libhxcadaptor/trunk/build/ mrproper
	$(MAKE) -C ../libhxcfe/trunk/build/ mrproper
	$(MAKE) -C ../libusbhxcfe/trunk/build/ mrproper
	$(MAKE) -C ../HxCFloppyEmulator_cmdline/trunk/build/ mrproper
	-rm -rf *.so
	-rm -rf *.a
	-rm -rf *.obj
	-rm -rf *.opt
	-rm -rf *.dll
	-rm -rf *.exe
	-rm -rf *.lib
	-rm -rf *.ncb
	-rm -rf *.exp
	-rm -rf *.dylib
	-rm -rf *.dmg
	-rm -rf *.app
	-rm -rf hxcfe_cmdline
	-rm -rf hxcfloppyemulator
	-rm -f  hxcfe hxcfe.static
	-rm -rf Debug_*
	-rm -rf Release_*
	-rm -rf ADFOpus_*

.PHONY: libhxcadaptor libhxcfe libusbhxcfe HxCFloppyEmulator_cmdline mrproper clean

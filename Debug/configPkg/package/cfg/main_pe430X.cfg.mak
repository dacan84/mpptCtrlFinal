# invoke SourceDir generated makefile for main.pe430X
main.pe430X: .libraries,main.pe430X
.libraries,main.pe430X: package/cfg/main_pe430X.xdl
	$(MAKE) -f C:\Users\Diegol\Documents\GitHub\mpptCtrlFinal/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Diegol\Documents\GitHub\mpptCtrlFinal/src/makefile.libs clean


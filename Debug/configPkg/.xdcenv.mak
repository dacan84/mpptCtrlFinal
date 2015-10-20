#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/grace_3_10_00_82/packages;C:/ti/msp430/MSPWare_2_30_00_49/driverlib/packages;C:/ti/msp430/MSPWare_2_30_00_49/driverlib;C:/ti/ccsv6/ccs_base
override XDCROOT = C:/ti/xdctools_3_31_01_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/grace_3_10_00_82/packages;C:/ti/msp430/MSPWare_2_30_00_49/driverlib/packages;C:/ti/msp430/MSPWare_2_30_00_49/driverlib;C:/ti/ccsv6/ccs_base;C:/ti/xdctools_3_31_01_33_core/packages;..
HOSTOS = Windows
endif

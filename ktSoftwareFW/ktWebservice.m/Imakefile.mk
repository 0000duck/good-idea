# COPYRIGHT Dassault Systemes 2011
#======================================================================
# Imakefile for module ktWebService.m
#======================================================================
#
#  Oct 2011  Creation: Code generated by the CAA wizard  Administrator
#======================================================================
#
# SHARED LIBRARY 
#
BUILT_OBJECT_TYPE=SHARED LIBRARY 
 
# DO NOT EDIT :: THE CAA2 WIZARDS WILL ADD CODE HERE
WIZARD_LINK_MODULES = JS0GROUP \
JS0GROUP JS0FM CATApplicationFrame DI0PANV2
# END WIZARD EDITION ZONE

LINK_WITH = $(WIZARD_LINK_MODULES)

# System dependant variables
#
OS = AIX
#
OS = HP-UX
#
OS = IRIX
#
OS = SunOS
#
OS = Windows_NT

LOCAL_CCFLAGS= / d4251

LOCAL_CCFLAGS = -I "C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\Include"
LOCAL_LDFLAGS = "C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\Lib\WSock32.Lib"

#LOCAL_CCFLAGS = -I "C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\Include"
#LOCAL_LDFLAGS = "C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\Lib\AMD64\WSock32.Lib"
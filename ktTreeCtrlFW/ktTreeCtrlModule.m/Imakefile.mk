# COPYRIGHT DASSAULT SYSTEMES 2010
#======================================================================
# Imakefile for module CAATreeCtrlModule.m
#======================================================================
#
#  Feb 2010  Creation: Code generated by the CAA wizard  user
#======================================================================
#
# SHARED LIBRARY 
#
BUILT_OBJECT_TYPE=SHARED LIBRARY 
 
# DO NOT EDIT :: THE CAA2 WIZARDS WILL ADD CODE HERE
WIZARD_LINK_MODULES = JS0GROUP \
DI0PANV2 JS0FM 
# END WIZARD EDITION ZONE

LINK_WITH = $(WIZARD_LINK_MODULES) ktTreeNodeImplement CATIAApplicationFrame CATObjectModelerBase ktTreeNodeInterface 

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

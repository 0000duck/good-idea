# COPYRIGHT Dassault Systemes 2011
#======================================================================
# Imakefile for module MBDPrtAddMaterialMod.m
#======================================================================
#
#  Feb 2011  Creation: Code generated by the CAA wizard  ev5adm
#======================================================================
#
# SHARED LIBRARY 
#
BUILT_OBJECT_TYPE=SHARED LIBRARY 
 
# DO NOT EDIT :: THE CAA2 WIZARDS WILL ADD CODE HERE
WIZARD_LINK_MODULES = JS0GROUP \
JS0GROUP JS0FM DI0PANV2 CATMathematics CATDialogEngine  \
CATApplicationFrame CATObjectModelerBase \
CATMatInterfaces Material CATMecModInterfaces KnowledgeItf CATObjectSpecsModeler \
ktWebservice ktBasicService ktDirFileService ktExcelService ktPrdService ktPrtService ktStrLogService ktXMLService\

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

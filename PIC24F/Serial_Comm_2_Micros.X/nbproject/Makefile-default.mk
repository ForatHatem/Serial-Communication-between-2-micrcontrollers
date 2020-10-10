#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=UART/UART_SETUP.h Digital_Input_Output/GPIO.h UART/UART_TX_RX.h Digital_Input_Output/TOGGLE_LED.h LCD.h ToggleLCD.h UART/UART_SETUP.c Digital_Input_Output/GPIO.c UART/UART_TX_RX.c main_PIC24.c Digital_Input_Output/TOGGLE_LED.c LCD.c ToggleLCD.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/UART/UART_SETUP.o ${OBJECTDIR}/Digital_Input_Output/GPIO.o ${OBJECTDIR}/UART/UART_TX_RX.o ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/ToggleLCD.o ${OBJECTDIR}/UART/UART_SETUP.o ${OBJECTDIR}/Digital_Input_Output/GPIO.o ${OBJECTDIR}/UART/UART_TX_RX.o ${OBJECTDIR}/main_PIC24.o ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/ToggleLCD.o
POSSIBLE_DEPFILES=${OBJECTDIR}/UART/UART_SETUP.o.d ${OBJECTDIR}/Digital_Input_Output/GPIO.o.d ${OBJECTDIR}/UART/UART_TX_RX.o.d ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d ${OBJECTDIR}/LCD.o.d ${OBJECTDIR}/ToggleLCD.o.d ${OBJECTDIR}/UART/UART_SETUP.o.d ${OBJECTDIR}/Digital_Input_Output/GPIO.o.d ${OBJECTDIR}/UART/UART_TX_RX.o.d ${OBJECTDIR}/main_PIC24.o.d ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d ${OBJECTDIR}/LCD.o.d ${OBJECTDIR}/ToggleLCD.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/UART/UART_SETUP.o ${OBJECTDIR}/Digital_Input_Output/GPIO.o ${OBJECTDIR}/UART/UART_TX_RX.o ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/ToggleLCD.o ${OBJECTDIR}/UART/UART_SETUP.o ${OBJECTDIR}/Digital_Input_Output/GPIO.o ${OBJECTDIR}/UART/UART_TX_RX.o ${OBJECTDIR}/main_PIC24.o ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/ToggleLCD.o

# Source Files
SOURCEFILES=UART/UART_SETUP.h Digital_Input_Output/GPIO.h UART/UART_TX_RX.h Digital_Input_Output/TOGGLE_LED.h LCD.h ToggleLCD.h UART/UART_SETUP.c Digital_Input_Output/GPIO.c UART/UART_TX_RX.c main_PIC24.c Digital_Input_Output/TOGGLE_LED.c LCD.c ToggleLCD.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ1024GB610
MP_LINKER_FILE_OPTION=,--script=p24FJ1024GB610.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/UART/UART_SETUP.o: UART/UART_SETUP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/UART" 
	@${RM} ${OBJECTDIR}/UART/UART_SETUP.o.d 
	@${RM} ${OBJECTDIR}/UART/UART_SETUP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART/UART_SETUP.c  -o ${OBJECTDIR}/UART/UART_SETUP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UART/UART_SETUP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/UART/UART_SETUP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Digital_Input_Output/GPIO.o: Digital_Input_Output/GPIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Digital_Input_Output" 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/GPIO.o.d 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Digital_Input_Output/GPIO.c  -o ${OBJECTDIR}/Digital_Input_Output/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Digital_Input_Output/GPIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/Digital_Input_Output/GPIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/UART/UART_TX_RX.o: UART/UART_TX_RX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/UART" 
	@${RM} ${OBJECTDIR}/UART/UART_TX_RX.o.d 
	@${RM} ${OBJECTDIR}/UART/UART_TX_RX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART/UART_TX_RX.c  -o ${OBJECTDIR}/UART/UART_TX_RX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UART/UART_TX_RX.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/UART/UART_TX_RX.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main_PIC24.o: main_PIC24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main_PIC24.o.d 
	@${RM} ${OBJECTDIR}/main_PIC24.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main_PIC24.c  -o ${OBJECTDIR}/main_PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main_PIC24.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/main_PIC24.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o: Digital_Input_Output/TOGGLE_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Digital_Input_Output" 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Digital_Input_Output/TOGGLE_LED.c  -o ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/LCD.o: LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD.c  -o ${OBJECTDIR}/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ToggleLCD.o: ToggleLCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ToggleLCD.o.d 
	@${RM} ${OBJECTDIR}/ToggleLCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ToggleLCD.c  -o ${OBJECTDIR}/ToggleLCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ToggleLCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/ToggleLCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/UART/UART_SETUP.o: UART/UART_SETUP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/UART" 
	@${RM} ${OBJECTDIR}/UART/UART_SETUP.o.d 
	@${RM} ${OBJECTDIR}/UART/UART_SETUP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART/UART_SETUP.c  -o ${OBJECTDIR}/UART/UART_SETUP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UART/UART_SETUP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/UART/UART_SETUP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Digital_Input_Output/GPIO.o: Digital_Input_Output/GPIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Digital_Input_Output" 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/GPIO.o.d 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Digital_Input_Output/GPIO.c  -o ${OBJECTDIR}/Digital_Input_Output/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Digital_Input_Output/GPIO.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/Digital_Input_Output/GPIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/UART/UART_TX_RX.o: UART/UART_TX_RX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/UART" 
	@${RM} ${OBJECTDIR}/UART/UART_TX_RX.o.d 
	@${RM} ${OBJECTDIR}/UART/UART_TX_RX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART/UART_TX_RX.c  -o ${OBJECTDIR}/UART/UART_TX_RX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UART/UART_TX_RX.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/UART/UART_TX_RX.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main_PIC24.o: main_PIC24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main_PIC24.o.d 
	@${RM} ${OBJECTDIR}/main_PIC24.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main_PIC24.c  -o ${OBJECTDIR}/main_PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main_PIC24.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/main_PIC24.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o: Digital_Input_Output/TOGGLE_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Digital_Input_Output" 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d 
	@${RM} ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Digital_Input_Output/TOGGLE_LED.c  -o ${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/Digital_Input_Output/TOGGLE_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/LCD.o: LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD.c  -o ${OBJECTDIR}/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ToggleLCD.o: ToggleLCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ToggleLCD.o.d 
	@${RM} ${OBJECTDIR}/ToggleLCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ToggleLCD.c  -o ${OBJECTDIR}/ToggleLCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ToggleLCD.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/ToggleLCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Serial_Comm_2_Micros.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

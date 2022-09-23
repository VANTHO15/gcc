.PHONY: clean build

PRO_DIR		:= .
PATH_OUTPUT = output
PROJ_NAME	:= S32K144_demo

INCLUDE_DIRS := $(PRO_DIR)/include
INCLUDE_DIRS += $(PRO_DIR)/src/App/LED
INCLUDE_DIRS += $(PRO_DIR)/src/Drivers/Clock
INCLUDE_DIRS += $(PRO_DIR)/src/Drivers/GPIO
INCLUDE_DIRS += $(PRO_DIR)/src/System/Init
INCLUDE_DIRS += $(PRO_DIR)/src/System/Sch
INCLUDE_DIRS += $(PRO_DIR)/src/System/Task

SRC_DIRS := $(PRO_DIR)/src/System/Init
SRC_DIRS += $(PRO_DIR)/src/System/Sch
SRC_DIRS += $(PRO_DIR)/src/System/Task
SRC_DIRS += $(PRO_DIR)/src/App/LED
SRC_DIRS += $(PRO_DIR)/src/Drivers/Clock
SRC_DIRS += $(PRO_DIR)/src/Drivers/GPIO
SRC_DIRS += $(PRO_DIR)/Project_Settings/Startup_Code
SRC_DIRS += $(PRO_DIR)/source

S_DIRD := $(PRO_DIR)/Project_Settings/Startup_Code


SRC_FILES      := $(foreach SRC_DIRS,$(SRC_DIRS),$(wildcard $(SRC_DIRS)/*.c))
INCLUDE_FILES  := $(foreach INCLUDE_DIRS,$(INCLUDE_DIRS),$(wildcard $(INCLUDE_DIRS)/*.h))
S_FILES  		:= $(foreach S_DIRD,$(S_DIRD),$(wildcard $(S_DIRD)/*.S))

LINKER_FILE	    := $(PRO_DIR)/Project_Settings/Linker_Files/S32K144_64_flash.ld
# LINKER_FILE	    += $(PRO_DIR)/Project_Settings/Linker_Files/S32K144_64_ram.ld
COMPILER_DIR 	:= C:/GCC_THO

CC				:= $(COMPILER_DIR)/bin/arm-none-eabi-gcc
LD				:= $(COMPILER_DIR)/bin/arm-none-eabi-ld
AC				:= $(COMPILER_DIR)/bin/arm-none-eabi-gcc

INCLUDE_DIRS_OPT := $(foreach INCLUDE_DIRS,$(INCLUDE_DIRS),-I$(INCLUDE_DIRS))

CC_OPT			:= -mcpu=cortex-m4 -c -O0 -g -mthumb -Wall -DDEBUG  $(INCLUDE_DIRS_OPT)
LD_OPT			:= -T $(LINKER_FILE) -Map $(PATH_OUTPUT)/$(PROJ_NAME).map
AC_OPT			:= -mcpu=cortex-m4 -g -mthumb $(S_DIRD)
# -mcpu=cortex-m4 -Os -g3 -mthumb -Wall -DDEBUG
# option	description					option       optimization level									-Wall: cho phép tất cả các thông báo cảnh báo của trình biên dịch
# -g0	no debug information			-O0			optimization for compilation time (default)
# -g1	minimal debug information		-O1 or -O	optimization for code size and execution time
# -g	default debug information		-O2			optimization more for code size and execution time
# -g3	maximal debug information		-Os			optimization for code size

OJB_FILES  := $(notdir $(SRC_FILES))
S_FILES  := $(notdir $(S_FILES))
OJB_FILES  := $(subst .c,.o,$(OJB_FILES))
OJB_TEMP  := $(subst .S,.o,$(S_FILES))
# OJB_FILES += $(OJB_TEMP)
PATH_OJBS  := $(foreach OJB_FILES,$(OJB_FILES),$(PATH_OUTPUT)/$(OJB_FILES))

vpath %.c $(SRC_DIRS)
vpath %.h $(INCLUDE_DIRS)
vpath %.S $(S_DIRD)

build: $(OJB_FILES) $(LINKER_FILE) $(PATH_OUTPUT)/$(OJB_TEMP)
	$(LD) $(LD_OPT) $(PATH_OJBS) -o $(PATH_OUTPUT)/$(PROJ_NAME).elf
	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$(PATH_OUTPUT)/$(PROJ_NAME).elf" "$(PATH_OUTPUT)/$(PROJ_NAME).hex"
	size $(PATH_OUTPUT)/$(PROJ_NAME).elf
	@echo "<--------------- ==AE== build ThoNV12 ---------------> [SUCCEEDED]"

%.o: %.c $(INCLUDE_FILES)
	mkdir -p $(PATH_OUTPUT)
	$(CC) $(CC_OPT) -c $< -o $(PATH_OUTPUT)/$@

$(PATH_OUTPUT)/$(OJB_TEMP): $(S_DIRD)/$(S_FILES)
	$(AC) $(AC_OPT) -c $< -o $@
# %.o: %.S $(S_FILES)
# 	$(AC) $(AC_OPT) -c $< -o $(PATH_OUTPUT)/$@


clean:
	rm -rf $(PATH_OUTPUT)/*

log-%:
	@echo $($(subst log-,,$@))
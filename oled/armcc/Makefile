
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif
endif

# List the subdirectories for creating object files
SUB_DIRS +=  \
 \
gfx_mono \
gfx_mono/display_controller \
gfx_mono/fonts \
gfx_mono/display \
hpl/dmac \
hal/src \
gfx_mono/display/ug2832hsweg04 \
armcc/Device/SAMR21/Source \
armcc/Device/SAMR21/Source/ARM \
hpl/pm \
hpl/sysctrl \
hal/utils/src \
hpl/sercom \
examples \
hpl/gclk \
gfx_mono/display_controller/ssd1306 \
hpl/core

# List the object files
OBJS +=  \
hal/src/hal_io.o \
gfx_mono/display_controller/ssd1306/ssd1306_font.o \
gfx_mono/display/ug2832hsweg04/ug2832hsweg04.o \
gfx_mono/display/framebuffer.o \
gfx_mono/display/display_mono.o \
hpl/sysctrl/hpl_sysctrl.o \
hal/src/hal_spi_m_sync.o \
gfx_mono/gfx_mono_text.o \
gfx_mono/gfx_mono.o \
hal/src/hal_delay.o \
gfx_mono_main.o \
hpl/core/hpl_init.o \
hal/utils/src/utils_list.o \
hpl/core/hpl_core_m0plus_base.o \
hal/utils/src/utils_assert.o \
hpl/dmac/hpl_dmac.o \
hpl/pm/hpl_pm.o \
hpl/gclk/hpl_gclk.o \
hal/src/hal_init.o \
main.o \
gfx_mono/display_controller/ssd1306/ssd1306.o \
examples/driver_examples.o \
armcc/Device/SAMR21/Source/system_samr21.o \
driver_init.o \
hpl/sercom/hpl_sercom.o \
gfx_mono/fonts/gfx_mono_font_basic_6x7.o \
gfx_mono/display_controller/display_ctrl_mono.o \
hal/src/hal_gpio.o \
hal/utils/src/utils_event.o \
hal/src/hal_sleep.o \
armcc/Device/SAMR21/Source/ARM/startup_SAMR21.o \
atmel_start.o \
hal/src/hal_atomic.o

OBJS_AS_ARGS +=  \
"hal/src/hal_io.o" \
"gfx_mono/display_controller/ssd1306/ssd1306_font.o" \
"gfx_mono/display/ug2832hsweg04/ug2832hsweg04.o" \
"gfx_mono/display/framebuffer.o" \
"gfx_mono/display/display_mono.o" \
"hpl/sysctrl/hpl_sysctrl.o" \
"hal/src/hal_spi_m_sync.o" \
"gfx_mono/gfx_mono_text.o" \
"gfx_mono/gfx_mono.o" \
"hal/src/hal_delay.o" \
"gfx_mono_main.o" \
"hpl/core/hpl_init.o" \
"hal/utils/src/utils_list.o" \
"hpl/core/hpl_core_m0plus_base.o" \
"hal/utils/src/utils_assert.o" \
"hpl/dmac/hpl_dmac.o" \
"hpl/pm/hpl_pm.o" \
"hpl/gclk/hpl_gclk.o" \
"hal/src/hal_init.o" \
"main.o" \
"gfx_mono/display_controller/ssd1306/ssd1306.o" \
"examples/driver_examples.o" \
"armcc/Device/SAMR21/Source/system_samr21.o" \
"driver_init.o" \
"hpl/sercom/hpl_sercom.o" \
"gfx_mono/fonts/gfx_mono_font_basic_6x7.o" \
"gfx_mono/display_controller/display_ctrl_mono.o" \
"hal/src/hal_gpio.o" \
"hal/utils/src/utils_event.o" \
"hal/src/hal_sleep.o" \
"armcc/Device/SAMR21/Source/ARM/startup_SAMR21.o" \
"atmel_start.o" \
"hal/src/hal_atomic.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"gfx_mono/display/display_mono.d" \
"gfx_mono/display/framebuffer.d" \
"hal/src/hal_gpio.d" \
"hal/src/hal_io.d" \
"gfx_mono/display/ug2832hsweg04/ug2832hsweg04.d" \
"gfx_mono/display_controller/ssd1306/ssd1306_font.d" \
"gfx_mono/fonts/gfx_mono_font_basic_6x7.d" \
"main.d" \
"gfx_mono/gfx_mono.d" \
"gfx_mono/gfx_mono_text.d" \
"hal/src/hal_spi_m_sync.d" \
"hpl/core/hpl_core_m0plus_base.d" \
"hal/utils/src/utils_list.d" \
"hpl/dmac/hpl_dmac.d" \
"hal/utils/src/utils_assert.d" \
"hal/src/hal_delay.d" \
"hpl/core/hpl_init.d" \
"gfx_mono_main.d" \
"hpl/gclk/hpl_gclk.d" \
"hal/src/hal_init.d" \
"driver_init.d" \
"armcc/Device/SAMR21/Source/system_samr21.d" \
"gfx_mono/display_controller/ssd1306/ssd1306.d" \
"hpl/pm/hpl_pm.d" \
"examples/driver_examples.d" \
"armcc/Device/SAMR21/Source/ARM/startup_SAMR21.d" \
"hal/src/hal_sleep.d" \
"hpl/sercom/hpl_sercom.d" \
"hal/utils/src/utils_event.d" \
"gfx_mono/display_controller/display_ctrl_mono.d" \
"hal/src/hal_atomic.d" \
"hpl/sysctrl/hpl_sysctrl.d" \
"atmel_start.d"

OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARMCC Linker
	$(QUOTE)armlink$(QUOTE) --ro-base 0x00000000 --entry 0x00000000 --rw-base 0x20000000 --entry Reset_Handler --first __Vectors \
--strict --summary_stderr --info summarysizes --map --xref --callgraph --symbols \
--info sizes --info totals --info unused --info veneers --list $(OUTPUT_FILE_NAME).map \
-o $(OUTPUT_FILE_NAME).elf --cpu Cortex-M0+ \
$(OBJS_AS_ARGS)

	@echo Finished building target: $@

# Compiler target(s)




%.o: %.c
	@echo Building file: $<
	@echo ARMCC Compiler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M0+ -D__SAMR21G18A__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sercom" -I"../hpl/sysctrl" -I"../hri" -I"../" -I"../config" -I"../gfx_mono" -I"../gfx_mono/display" -I"../gfx_mono/display/ug2832hsweg04" -I"../gfx_mono/display_controller" -I"../gfx_mono/display_controller/ssd1306" -I"../gfx_mono/fonts" -I"../" -I"../CMSIS/Core/Include" -I"../include"  \
--depend "$@"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARMCC Assembler
	$(QUOTE)armasm$(QUOTE) -g --apcs=interwork --cpu Cortex-M0+ --pd "D__SAMR21G18A__ SETA 1" \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sercom" -I"../hpl/sysctrl" -I"../hri" -I"../" -I"../config" -I"../gfx_mono" -I"../gfx_mono/display" -I"../gfx_mono/display/ug2832hsweg04" -I"../gfx_mono/display_controller" -I"../gfx_mono/display_controller/ssd1306" -I"../gfx_mono/fonts" -I"../" -I"../CMSIS/Core/Include" -I"../include"  \
--depend "$(@:%.o=%.d)" -o "$@" "$<"

	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARMCC Preprocessing Assembler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M0+ -D__SAMR21G18A__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sercom" -I"../hpl/sysctrl" -I"../hri" -I"../" -I"../config" -I"../gfx_mono" -I"../gfx_mono/display" -I"../gfx_mono/display/ug2832hsweg04" -I"../gfx_mono/display_controller" -I"../gfx_mono/display_controller/ssd1306" -I"../gfx_mono/fonts" -I"../" -I"../CMSIS/Core/Include" -I"../include"  \
--depend "$@"  -o "$@" "$<"

	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).map $(OUTPUT_FILE_NAME).elf

# Normally, G_AT is '@', which causes commands to run silently. By overriding this from the
# command line, a make run can be instantly made fully verbose, which is helpful for debugging.
# Example - to debug the makefiles change the line below from "G_AT := @" to: "G_AT :="
# ---------------------------------------------------------------------------------------------
G_AT :=@

# Normally, G_NPD is '--no-print-directory', which keeps make from printing directory names
# as it enters and exits them. But at times, it's handy to see this information. To do this,
# simply change the line below to be a blank definition. You must also change G_AT to "G_AT :="
G_NPD :=--no-print-directory

# Define compiler 
CC := gcc

# ------------------------

VANTAGE_HOME = "C:/prog/VERASONICS"
INC := \
	-I$(VANTAGE_HOME)/dev-apps/c-hwdiag-app/src/includes \
	-I$(VANTAGE_HOME)/dev-libs/hal-lib/c-lib/src/includes \
	-I$(VANTAGE_HOME)/dev-libs/common-lib/c-common/src/includes \
	-I$(VANTAGE_HOME)/build/artifacts/includes/hal-lib \
	-I$(VANTAGE_HOME)/build/artifacts/includes/verasonics-common
LIBPATH := -L$(VANTAGE_HOME)/build/artifacts/win64/win64
LIBS := -lVerasonicsHal-NG

CFLAGS = -lstdc++ -fpermissive 

OBJ = main.obj VeraAPI.obj

all: main

%.obj: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(INC)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(INC) $(LIBPATH) $(LIBS)


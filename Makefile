SRC_DIR := BetterInventoryExport
OBJ_DIR := build
DLL := $(OBJ_DIR)/BetterInventoryExport.dll

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(SRC_FILES:.cpp=.obj)

BAKKESMOD_SDK_DIR := ../BakkesModSDK

CFLAGS := /nologo /EHsc /std:c++17 /I $(BAKKESMOD_SDK_DIR)/include /I /opt/msvc/vc/tools/msvc/14.31.31103/include /I /opt/msvc/vc/tools/msvc/14.31.31103/include/experimental
LDLIBS := pluginsdk.lib
LDFLAGS := /dll /LIBPATH:$(BAKKESMOD_SDK_DIR)/lib $(LDLIBS)

MSVC_PATH := /opt/msvc/bin/x64
CC := $(MSVC_PATH)/cl.exe
LD := $(MSVC_PATH)/link.exe

define do_compile
	$(eval $@_OUTDIR := $(shell dirname $@))
	@mkdir -p $($@_OUTDIR)
	$(CC) $(CFLAGS) /Fo"$($@_OUTDIR)/" /c $<
endef

all: $(DLL)

$(DLL): $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
	$(LD) $(LDFLAGS) /OUT:$@ $^

$(OBJ_DIR)/%.obj: %.cpp
	$(call do_compile)

patch:
	python $(BAKKESMOD_SDK_DIR)/bakkes_patchplugin.py "$(DLL)"

clean:
	rm -r $(OBJ_DIR)

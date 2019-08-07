##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SM
ConfigurationName      :=Debug
WorkspacePath          :=/home/steve/Documents/CPP
ProjectPath            :=/home/steve/Documents/CPP/SMART_MIRROR/SM
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Steve
Date                   :=07/08/19
CodeLitePath           :=/home/steve/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SM.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/home/steve/Documents/CPP/SMART_MIRROR/SM/include/pistache/include/pistache 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)pistache $(LibrarySwitch)pistache 
ArLibs                 :=  "libpistache.a" "libpistache.so" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/home/steve/Documents/CPP/SMART_MIRROR/SM/include/pistache/build/src 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/List.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListUtil.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListItem.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/steve/Documents/CPP/SMART_MIRROR/SM/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/List.cpp$(ObjectSuffix): List.cpp $(IntermediateDirectory)/List.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/steve/Documents/CPP/SMART_MIRROR/SM/List.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/List.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/List.cpp$(DependSuffix): List.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/List.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/List.cpp$(DependSuffix) -MM List.cpp

$(IntermediateDirectory)/List.cpp$(PreprocessSuffix): List.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/List.cpp$(PreprocessSuffix) List.cpp

$(IntermediateDirectory)/ListUtil.cpp$(ObjectSuffix): ListUtil.cpp $(IntermediateDirectory)/ListUtil.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/steve/Documents/CPP/SMART_MIRROR/SM/ListUtil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListUtil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListUtil.cpp$(DependSuffix): ListUtil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ListUtil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ListUtil.cpp$(DependSuffix) -MM ListUtil.cpp

$(IntermediateDirectory)/ListUtil.cpp$(PreprocessSuffix): ListUtil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListUtil.cpp$(PreprocessSuffix) ListUtil.cpp

$(IntermediateDirectory)/ListItem.cpp$(ObjectSuffix): ListItem.cpp $(IntermediateDirectory)/ListItem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/steve/Documents/CPP/SMART_MIRROR/SM/ListItem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListItem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListItem.cpp$(DependSuffix): ListItem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ListItem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ListItem.cpp$(DependSuffix) -MM ListItem.cpp

$(IntermediateDirectory)/ListItem.cpp$(PreprocessSuffix): ListItem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListItem.cpp$(PreprocessSuffix) ListItem.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



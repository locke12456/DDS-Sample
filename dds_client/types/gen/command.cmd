set LINK_IDL_PATH=%OSPL_HOME%\etc\idl
set IDL_PATH=""
set MARCOS_HEADER=OS_SEMADDS_API,semadds_export.h
"%OSPL_HOME%\bin\idlpp" -I "%LINK_IDL_PATH%" -n "any.hpp" -l cpp -P %MARCOS_HEADER% %IDL_PATH%semadds.idl 

set LINK_IDL_PATH=%OSPL_HOME%\etc\idl
set IDL_PATH=idl\
set MARCOS_HEADER=OS_SEMADDS_API,inc\semadds_export.h
"%OSPL_HOME%\bin\idlpp" -I "%LINK_IDL_PATH%" -l cpp -P %MARCOS_HEADER% %IDL_PATH%semadds.idl 

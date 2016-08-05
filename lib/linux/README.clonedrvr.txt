This describes the clonedrvr.sh in the dwmodbus directory.

NOTE TO DEVELOPERS:
The clonedrvr.sh script file will run only in a Linux development
environment. 
 
If you modify any files in the dwmodbus project, you MUST re-verify that the 
clonedrvr.sh script still works.  It is highly dependent on the way that the 
dwmodbus files are coded.

NOTE TO USERS:

clonedrvr.sh is a shell script that will replicate the dwmodbus driver 
into a new driver.
It is a part of the SEMA Cloud Software Development Kit (dwsdk).  
It will allow one to create a "clone" of the dwmodbus SEMA Cloud driver - located 
in the dwmodbus directory - into a new directory named as specified in 
the syntax description.  The new directory will be created at the 
same level as the dwmodbus directory.

Syntax:

./clonedrvr.sh -d drivername -c'Company Name'

	where:	drivername:	Name of the new driver
				must have NO embedded blanks
				Case insensitive.
		CompanyName:	Name of company developing the driver.  
				This name may have embedded blanks	
				if embedded blanks, must be enclosed in 
				quotation marks.
				Case sensitive.

Usage:

Install the SDK for the platform you wish to create a device driver and then 
issue the following commands at the command line:

cd /dwsdk_directory/dwmodbus_directory
chmod ugo+x clonedrvr.sh
./clonedrvr.sh -d Driver_Name -c "Company Name"

Note that dwsdk_directory is the directory containing the SEMA Cloud SDK; and
dwmodbus_directory is dwmodbus.

The new driver will be created in the directory /dwsdk_directory/driver_name

For example, issuing the command

./clonedrvr.sh -d ABC_Driver -c "ABC Corp"

will create a driver named abc_driver in /dwsdk_directory/abc_driver.
The new abc_driver will be a clone of the dwmodbus driver, except for having
the new name (abc_driver) instead of the dwmodbus references.

Note the case insensitivity of the driver name.

You may then cd to that directory and continue to develop the driver according 
to your device specifications; using the dwmodbus driver as your example

To compile and link the driver:

Linux like systems:

cd /dwsdk_directory/abc_driver
chmod +x configure
./configure
make

VXWorks:

cd /dwsdk_directory/abc_driver
chmod +x configure
./configure
make -f Makefile.vxworks

Windows XP:

cd \dwsdk_directory\abc_driver
.\configure.bat
nmake

You may also use the Microsoft Visual Studio and the project file 
/dwsdk_directory/abc_driver/MSVC/abc_driver.vcproj.

The driver will be a shared library (DLL) named as follows:

Linux & VXWorks -	libdriver_dame.so
Windows XP -		driver_dame.dll

This file must be copied to the directory where SEMA Cloud is installed. 
In the plugins directory.

While developing your driver, you will have to obtain a "device type" 
from ADLINK Technology Inc.  

See the file dwmodbus/devicewise/modbus.h; line with "MODBUS_TYPE_GENERIC"
Also, if you require licensing restrictions for your driver, you must uncomment 
the line in dwmodbus/src/dwmodbus.c; line with "device_type_set_license".
And obtain from ILS Technology suitable values for 
dwmodbus/devicewise/modbus.h; line with MODBUS_LIC_PRODUCT/FEATURE.

If you want to debug or watch the behavior of the modbus tcp device driver, 
you can obtain a modbus tcp device simulator for free from Internet sites.
One such that is known to work is at http://www.plcsimulator.org.

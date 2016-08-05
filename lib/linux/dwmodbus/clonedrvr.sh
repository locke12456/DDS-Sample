#!/bin/sh
#set -x
##----------------------------------------------------------------
##
##-- Filename: clonedrvr.sh
##
##-- $Date: 2011/08/30 15:22:34 $
##-- $Revision: 1.1 $
##-- $Name:  $
##
##----------------------------------------------------------------
# input parms:
#   -c company		chg all "ILS Technology" to "company"
#   -d drivername	chg all "MODBUS" to "DRIVERNAME"
#                	chg all "modbus" to "drivername"
#                	chg all "Modbus" to "Drivername"
#			etc...       
#   
#
#

function Usage {
   echo "Usage: $0 -d driver_name [-c company_name]"
   echo "       -c              name of the company developing the driver"
   echo "       -d              name of the driver"
   rm -f clone.sed
   exit 0
}

function chkrc {
   typeset -i rc=$1
   if [ $rc != 0 ]; then
      echo "error $rc on previous command"
      Usage
   fi
}

function dosed {
   if [ ! -z "$trace" ]; then
      set -x
   fi
    echo "Creating $2"
    sed -f $basedir/clone.sed $1 > clone.out
    chkrc $? 
    mv clone.out $2
    rm -f clone.out
}

# MAIN main

while getopts "c:C:d:D:tT" opt; do
    case $opt in
        [cC])
           company=$OPTARG
           if [ -z "$company" ]; then
              company=""
           fi
           ;;
        [dD])
           dname=$OPTARG
           if [ -z "$dname" ]; then
              Usage
           fi
           ;;
        [tT])
	   trace=1
           set -x
           ;;
        *)
           Usage
           ;;
    esac
done

model=dwmodbus
sys=`uname`
osname=`uname`
kernel=`uname -r|sed 's/...-.*$//'|sed 's/\./-/g'`
arch=`uname -m`
echo "sys=$sys"
echo "osname=$osname"
echo "kernel=$kernel"
echo "arch=$arch"

if [ -d $model ]; then
   echo "cd to $model directory"
   cd $model
fi
cd ..
if [ ! -d $model ]; then
   echo "There must be a $model directory"
   Usage
fi
basedir=`pwd`

case $sys in
   "Linux")
      osname=${sys}-${kernel}
      ;;
   *)
      osname=$sys
      ;;
esac 
if [ -z "$dname" ]; then
   Usage
fi
shift $(($OPTIND - 1))

dnamel="`echo $dname | tr \'[A-Z]\' \'[a-z]\'`"
dnameu="`echo $dname | tr \'[a-z]\' \'[A-Z]\'`"
a=`echo $dnamel | cut -c 1|tr a-z A-Z`
b=`echo $dnamel | cut -b2-`
dnameu1="$a$b"
dnamedw="${dnamel#dw*}"
modeldw="${model#dw*}"
echo "Building DeviceWISE Project (driver) $dnamel"
echo "  Company Name:   ${company}"
echo "  Driver Name:    ${dnamel}"
drdir=$basedir/$dnamel

if [ -d "$drdir" ]; then
   echo "$drdir exists; please remove it prior to running $0 again"
   rm -f clone.sed
   exit 1
fi

case $sys in
    # for MKS Toolkit, Cygwin, Minimal GNU respectively
    "Windows_NT"|"CYGWIN_NT-5.1"|"MINGW32_NT-5.1")
        echo "Creating on $sys"
        ;;
    "Linux")
        echo "Creating on Linux"
        ;;
    *)
        echo "Unknown system architecture"
        Usage
        ;;
esac

rm -f clone.sed   
echo "s#TCP#PKT#g"                        >> $basedir/clone.sed
echo "s#dwmodbus#$dnamel#g"                   >>  $basedir/clone.sed
echo "s#DWMODBUS#$dnameu#g"                   >>  $basedir/clone.sed
echo "s#MODBUS#$dnameu#g"                     >> $basedir/clone.sed
echo "s#modbus#$dnamel#g"                     >> $basedir/clone.sed
echo "s#Modbus#$dnameu1#g"                    >> $basedir/clone.sed
echo "s#ILS Technology#$company#g"            >> $basedir/clone.sed
echo "s#deviceWISE#deviceWISE implemented#g"  >> $basedir/clone.sed
echo "s#tcp.h#pkt.h#g"                        >> $basedir/clone.sed
echo "s#tcp#$dnamel#g"                        >> $basedir/clone.sed
echo "#device_type_set_license#//device_type_set_license#g"   >> $basedir/clone.sed 

for ff in src devicewise/$dnamel MSVC objs; do
   mkdir -p $drdir/$ff
   chkrc $? 
done

cd $basedir/$model/src
for ff in `ls *.c`; do
   case $ff in
        tcp.device.c)
          dosed $ff  $drdir/src/$dnamel.device.c
          ;;
        tcp.read.c)
          dosed $ff  $drdir/src/$dnamel.read.c
          ;;
        tcp.write.c)
          dosed $ff  $drdir/src/$dnamel.write.c
          ;;
        version.c)
          dosed $ff  $drdir/src/version.c
          ;;
        dwmodbus.c)
          dosed $ff  $drdir/src/$dnamel.c
          ;;
        *)
           echo "Warning, unknown file $ff"
           ;;
   esac
done
cd $basedir/$model/devicewise/$modeldw
for ff in `ls *.h`; do
   case $ff in
        modbus.h)
           dosed $ff $drdir/devicewise/$dnamedw/$dnamel.h
           ;;
        tcp.h)
           dosed $ff $drdir/devicewise/$dnamedw/pkt.h
           ;;
        *)
           echo "Warning, unknown file $ff"
           ;;
   esac
done
cd $basedir/$model/MSVC
for ff in `ls $model.*`; do
   case $ff in
        $model.rc)
           dosed $ff $drdir/MSVC/$dnamel.rc
           ;;
        $model.sln)
           dosed $ff $drdir/MSVC/$dnamel.sln
           ;;
        $model.vcproj)
           dosed $ff $drdir/MSVC/$dnamel.vcproj
           ;;
        $model.vcxproj)
           dosed $ff $drdir/MSVC/$dnamel.vcxproj
           ;;
        $model.vcxproj)
           dosed $ff $drdir/MSVC/$dnamel.vcxproj
           ;;
        $model.vcxproj.user)
           dosed $ff $drdir/MSVC/$dnamel.vcxproj.user
           ;;
        $model.vcxproj.filters)
           dosed $ff $drdir/MSVC/$dnamel.vcxproj.filters
           ;;
        *)
           echo "Warning, unknown file $ff"
           ;;
   esac
done
cd $basedir
dosed $model/version $drdir/version
dosed $model/Makefile.w32 $drdir/Makefile.w32
dosed $model/Makefile.vxworks $drdir/Makefile.vxworks
dosed $model/Makefile.in $drdir/Makefile.in
cp -fp $model/configure* $drdir/
chkrc $? 
rm -f clone.sed

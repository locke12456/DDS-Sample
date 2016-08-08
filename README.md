Step 1.

[OS]
Ubuntu 12.04 i686

[VortexOpenSplice version]
6.6.3 (x86)

[environment setup]
. /home/{user}/PrismTech/Vortex_v2/Device/VortexOpenSplice/6.6.3/HDE/x86.linux/release.com
export OSPL_URI=file:///home/{user}/PrismTech/Vortex_v2/Device/VortexOpenSplice/6.6.3/HDE/x86.linux/etc/config/ospl_sp_nativeRT.xml


Install VortexOpenSplice and setup environment.


Step 2.
[source code]
https://github.com/locke12456/DDS-Sample.git

Clone sources code form github.

Step 3.
[3rdLib]
https://drive.google.com/file/d/0B9gRBqzd6q6iQU1pajl1X05FR0U/view?usp=sharing
download and unzip to soure code folder.

Step 4.
use cmake to build sample.


[setup path]
/home/{user}/PrismTech/Vortex_v2/Device/VortexOpenSplice/6.6.3/HDE/x86.linux

[ospl configures]
location : /home/{user}/PrismTech/Vortex_v2/Device/VortexOpenSplice/6.6.3/HDE/x86.linux/etc/config/

ospl_shmem_ddsi2e.xml                ospl_sp_ddsi_nativeRT_cohabitation.xml
ospl_shmem_ddsi.xml                  ospl_sp_ddsi_statistics.xml
ospl_shmem_nativeRT_ddsi_bridge.xml  ospl_sp_ddsi.xml
ospl_shmem_nativeRT.xml              ospl_sp_nativeRT.xml
ospl_shmem_no_network.xml            ospl_sp_no_network.xml
ospl_shmem_secure_nativeRT.xml       ospl.xml

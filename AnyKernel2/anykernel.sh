# AnyKernel2 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() {
kernel.string=HpyerPlus Kernel by ajituchiha @ xda-developers
do.devicecheck=0
do.modules=0
do.cleanup=1
do.cleanuponabort=1
device.name1=
device.name2=
} # end properties

# shell variables
block=/dev/block/sdd36;
is_slot_device=0;
ramdisk_compression=auto;


## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. /tmp/anykernel/tools/ak2-core.sh;


## AnyKernel boot install

ui_print " ";
ui_print "Adding flavour to the kernel.....";

dump_boot;

# add spectrum support
insert_line init.rc "import /init.spectrum.rc" "before" "import /init.rphone.rc" "import /init.spectrum.rc"

write_boot;

## end install


# shell variables
block=/dev/block/sdd35;
ramdisk_compression=auto;

# reset for recovery patching
reset_ak;


## AnyKernel zImage install
ui_print "Adding a little more flavor in there.....";

split_boot;

flash_boot;

## end install


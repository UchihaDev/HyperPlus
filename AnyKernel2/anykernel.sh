# AnyKernel2 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() {
kernel.string=HyperPlus Kernel by ajituchiha @ xda-developers
do.devicecheck=0
do.modules=0
do.cleanup=1
do.cleanuponabort=1
device.name1=
device.name2=
} # end properties

## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. /tmp/anykernel/tools/ak2-core.sh;


# shell variables
block=/dev/block/platform/ff3b0000.ufs/by-name/ramdisk;
is_slot_device=1;
ramdisk_compression=auto;


## AnyKernel ramdisk install

ui_print " ";
ui_print "Adding flavor to the kernel...";

dump_boot;

# add spectrum support
insert_line init.rc "import /init.spectrum.rc" "before" "import /init.rphone.rc" "import /init.spectrum.rc";

write_boot;

## end install


# shell variables
block=/dev/block/platform/ff3b0000.ufs/by-name/kernel;
ramdisk_compression=auto;

# reset for kernel patching
reset_ak;
mv /tmp/anykernel/kernel-Image.gz /tmp/anykernel/Image.gz;


## AnyKernel kernel install

ui_print "Adding a little more flavor in there...";

split_boot;

flash_boot;

## end install

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

ui_print " ";
ui_print " ";
ui_print " __  __     __  __     ______   ______     ______     ";
ui_print "/\ \_\ \   /\ \_\ \   /\  == \ /\  ___\   /\  == \    ";
ui_print "\ \  __ \  \ \____ \  \ \  _-/ \ \  __\   \ \  __<    ";
ui_print " \ \_\ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  ";
ui_print "  \/_/\/_/   \/_____/   \/_/     \/_____/   \/_/ /_/  ";
ui_print " ";
ui_print " ______   __         __  __     ______                ";
ui_print "/\  == \ /\ \       /\ \/\ \   /\  ___\               ";
ui_print "\ \  _-/ \ \ \____  \ \ \_\ \  \ \___  \              ";
ui_print " \ \_\    \ \_____\  \ \_____\  \/\_____\             ";
ui_print "  \/_/     \/_____/   \/_____/   \/_____/             ";
ui_print " ";

# shell variables
block=/dev/block/bootdevice/by-name/ramdisk;
is_slot_device=auto;
ramdisk_compression=auto;


## AnyKernel ramdisk install

ui_print " ";
ui_print "Adding flavor to the kernel...";

dump_boot;

# make schedutil default governor
insert_line init.rc '# set governor' 'before' '# scheduler tunables' '# set governor'
insert_line init.rc 'write /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor "schedutil"' 'after' '# set governor' 'write /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor "schedutil"'
insert_line init.rc 'write /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor "schedutil"' 'after' 'write /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor "schedutil"' 'write /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor "schedutil"'

write_boot;

## end install


# shell variables
block=/dev/block/bootdevice/by-name/kernel;
ramdisk_compression=auto;

# reset for kernel patching
reset_ak;
mv /tmp/anykernel/kernel-Image.gz /tmp/anykernel/Image.gz;


## AnyKernel kernel install

ui_print "Adding a little more flavor in there...";

split_boot;

flash_boot;

## end install

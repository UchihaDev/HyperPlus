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

## AnyKernel file attributes
# set permissions/ownership for included ramdisk files
chmod -R 750 $ramdisk/*;
chown -R root:root $ramdisk/*;

# add default values 1
insert_line init.rc '# set default schedTune value for foreground/top-app (only affects EAS)' 'before' '# Mount staging areas for devices managed by vold' '# set default schedTune value for foreground/top-app (only affects EAS)'
insert_line init.rc 'write /dev/stune/foreground/schedtune.prefer_idle 1' 'after' '# set default schedTune value for foreground/top-app (only affects EAS)' 'write /dev/stune/foreground/schedtune.prefer_idle 1'
insert_line init.rc 'write /dev/stune/top-app/schedtune.prefer_idle 1' 'after' 'write /dev/stune/foreground/schedtune.prefer_idle 1' 'write /dev/stune/top-app/schedtune.prefer_idle 1'
insert_line init.rc 'write /dev/stune/top-app/schedtune.boost 7' 'after' 'write /dev/stune/top-app/schedtune.prefer_idle 1' 'write /dev/stune/top-app/schedtune.boost 10'

# add default values 2
insert_line init.rc '# update cpusets now that processors are up' 'before' '# Start standard binderized HAL daemons' '# update cpusets now that processors are up'
insert_line init.rc 'write /dev/stune/foreground/schedtune.prefer_idle 1' 'after' '# update cpusets now that processors are up' 'write /dev/stune/foreground/schedtune.prefer_idle 1'
insert_line init.rc 'write /dev/stune/top-app/schedtune.prefer_idle 1' 'after' 'write /dev/stune/foreground/schedtune.prefer_idle 1' 'write /dev/stune/top-app/schedtune.prefer_idle 1'
insert_line init.rc 'write /dev/stune/top-app/schedtune.boost 1' 'after' 'write /dev/stune/top-app/schedtune.prefer_idle 1' 'write /dev/stune/top-app/schedtune.boost 1'

# make schedutil default governor
insert_line init.rc '# set governor' 'before' '# scheduler tunables' '# set governor'
insert_line init.rc 'write /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor "schedutil"' 'after' '# set governor' 'write /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor "schedutil"'
insert_line init.rc 'write /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor "schedutil"' 'after' 'write /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor "schedutil"' 'write /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor "schedutil"'

# add default values 3
insert_line init.rc 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/up_rate_limit_us 500' 'after' 'write /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor "schedutil"' 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/up_rate_limit_us 500'
insert_line init.rc 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/down_rate_limit_us 20000' 'after' 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/up_rate_limit_us 500' 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/down_rate_limit_us 20000'
insert_line init.rc 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/iowait_boost_enable 1' 'after' 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/down_rate_limit_us 20000' 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/iowait_boost_enable 1'
insert_line init.rc 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/up_rate_limit_us 500' 'after' 'write /sys/devices/system/cpu/cpu0/cpufreq/schedutil/iowait_boost_enable 1' 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/up_rate_limit_us 500'
insert_line init.rc 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/down_rate_limit_us 20000' 'after' 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/up_rate_limit_us 500' 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/down_rate_limit_us 20000'
insert_line init.rc 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/iowait_boost_enable 1' 'after' 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/down_rate_limit_us 20000' 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/iowait_boost_enable 1'
insert_line init.rc 'write /sys/module/cpu_boost/parameters/input_boost_freq "0:1036800"' 'after' 'write /sys/devices/system/cpu/cpu4/cpufreq/schedutil/iowait_boost_enable 1' 'write /sys/module/cpu_boost/parameters/input_boost_freq "0:1036800"'
insert_line init.rc 'write /sys/module/cpu_boost/parameters/dynamic_stune_boost 5' 'after' 'write /sys/module/cpu_boost/parameters/input_boost_freq "0:1036800"' 'write /sys/module/cpu_boost/parameters/dynamic_stune_boost 5'
insert_line init.rc 'write /sys/module/cpu_boost/parameters/input_boost_ms 500' 'after' 'write /sys/module/cpu_boost/parameters/dynamic_stune_boost 5' 'write /sys/module/cpu_boost/parameters/input_boost_ms 500'
insert_line init.rc 'write /sys/block/sda/queue/read_ahead_kb 1024' 'after' 'write /sys/module/cpu_boost/parameters/input_boost_ms 500' 'write /sys/block/sda/queue/read_ahead_kb 1024'
insert_line init.rc 'write /sys/block/sda/queue/nr_requests 128' 'after' 'write /sys/block/sda/queue/read_ahead_kb 1024' 'write /sys/block/sda/queue/nr_requests 128'
insert_line init.rc 'write /sys/block/sda/queue/iostats 1' 'after' 'write /sys/block/sda/queue/nr_requests 128' 'write /sys/block/sda/queue/iostats 1'

write_boot;

## end install


# shell variables
block=/dev/block/bootdevice/by-name/kernel;
ramdisk_compression=auto;

# reset for kernel patching
reset_ak;
mv /tmp/anykernel/kernel-Image.gz /tmp/anykernel/Image.gz;


## AnyKernel kernel install

split_boot;

flash_boot;

## end install

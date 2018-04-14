#!/bin/bash
BUILD_START=$(date +"%s")

# Colours
blue='\033[0;34m'
cyan='\033[0;36m'
yellow='\033[0;33m'
red='\033[0;31m'
nocol='\033[0m'

# Kernel details
KERNEL_NAME="HyperPlus"
VERSION="Gatorade_V2"
DATE=$(date +"%d-%m-%Y-%I-%M")
DEVICE="VKY"
FINAL_ZIP=$KERNEL_NAME-$VERSION-$DATE-$DEVICE.zip

# Dirs
KERNEL_DIR=~/Desktop/Code_Opensource
OUT_DIR=~/Desktop/out
UPLOAD_DIR=~/Desktop/Files/flash_zip
ANYKERNEL_DIR=$KERNEL_DIR/AnyKernel2
KERNEL_IMG=~/Desktop/out/arch/arm64/boot/Image.gz

# Delete these annoying files
rm -rf mm/.memory.c.swp
rm -rf net/.Kconfig.swp
rm -rf arch/x86/kernel/cpu/bugs_64.c

# Export
export PATH=$PATH:~/Desktop/tools/toolchain/gcc-linaro-4.9.4/bin
export CROSS_COMPILE=aarch64-linux-gnu-

# Make kernel
function make_kernel() {
  echo -e "$cyan***********************************************"
  echo -e "          Initializing defconfig          "
  echo -e "***********************************************$nocol"
  make ARCH=arm64 O=../out hyperplus_defconfig
  echo -e "$cyan***********************************************"
  echo -e "             Building kernel          "
  echo -e "***********************************************$nocol"
  make ARCH=arm64 O=../out -j8
  if ! [ -a $KERNEL_IMG ];
  then
    echo -e "$red Kernel Compilation failed! Fix the errors! $nocol"
    exit 1
  fi
}

# Making zip
function make_zip() {
cp $KERNEL_IMG $ANYKERNEL_DIR/kernel-Image.gz
mkdir -p $UPLOAD_DIR
cd $ANYKERNEL_DIR
zip -r9 UPDATE-AnyKernel2.zip * -x README UPDATE-AnyKernel2.zip
mv $ANYKERNEL_DIR/UPDATE-AnyKernel2.zip $UPLOAD_DIR/VKY/$FINAL_ZIP
}

# Options
function options() {
  echo -e "$cyan                                                 "
  echo -e " __  __     __  __     ______   ______     ______     "
  echo -e "/\ \_\ \   /\ \_\ \   /\  == \ /\  ___\   /\  == \    "
  echo -e "\ \  __ \  \ \____ \  \ \  _-/ \ \  __\   \ \  __<    "
  echo -e " \ \_\ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  "
  echo -e "  \/_/\/_/   \/_____/   \/_/     \/_____/   \/_/ /_/  "
  echo -e " "
  echo -e " ______   __         __  __     ______                "
  echo -e "/\  == \ /\ \       /\ \/\ \   /\  ___\               "
  echo -e "\ \  _-/ \ \ \____  \ \ \_\ \  \ \___  \              "
  echo -e " \ \_\    \ \_____\  \ \_____\  \/\_____\             "
  echo -e "  \/_/     \/_____/   \/_____/   \/_____/             "
  echo -e "                                                 $noco"
echo -e "$cyan***********************************************"
  echo "          Compiling HyperPlus kernel          "
  echo -e "***********************************************$nocol"
  echo -e " "
  echo -e " Select one of the following types of build : "
  echo -e " 1.Dirty"
  echo -e " 2.Clean"
  echo -n " Your choice : ? "
  read ch
  echo
  echo
  echo -e " Select if you want zip or just kernel : "
  echo -e " 1.Get flashable zip"
  echo -e " 2.Get kernel only"
  echo -n " Your choice : ? "
  read ziporkernel
  echo
  echo

case $ch in
  1) echo -e "$cyan***********************************************"
     echo -e "          	Dirty          "
     echo -e "***********************************************$nocol"
     make_kernel ;;
  2) echo -e "$cyan***********************************************"
     echo -e "          	Clean          "
     echo -e "***********************************************$nocol"
     make ARCH=arm64 distclean
     rm -rf ../out
     cp -r ~/Desktop/android/drivers/huawei_platform/lcd/tools/localperl/lib/5.14.2/x86_64-linux-thread-multi/CORE/libperl.a drivers/huawei_platform/lcd/tools/localperl/lib/5.14.2/x86_64-linux-thread-multi/CORE/libperl.a
     cp -r ~/Desktop/android/scripts/kconfig/zconf.hash.c scripts/kconfig/zconf.hash.c
     cp -r ~/Desktop/android/scripts/kconfig/zconf.lex.c scripts/kconfig/zconf.lex.c
     cp -r ~/Desktop/android/scripts/kconfig/zconf.tab.c scripts/kconfig/zconf.tab.c
     make_kernel ;;
esac

     echo
     echo

if [ "$ziporkernel" = "1" ]; then
     echo -e "$cyan***********************************************"
     echo -e "     Making flashable zip        "
     echo -e "***********************************************$nocol"
     make_zip
else
     echo -e "$cyan***********************************************"
     echo -e "     Building Kernel only        "
     echo -e "***********************************************$nocol"
fi
}

# Clean Up
function cleanup(){
rm -rf $ANYKERNEL_DIR/kernel-Image.gz
rm -rf $ANYKERNEL_DIR/Image
rm -rf $ANYKERNEL_DIR/modules/*.ko
rm -rf $KERNEL_DIR/arch/arm/boot/dts/*.dtb
}

options
cleanup
BUILD_END=$(date +"%s")
DIFF=$(($BUILD_END - $BUILD_START))
echo -e "$yellow Build completed in $(($DIFF / 60)) minute(s) and $(($DIFF % 60)) seconds.$nocol"


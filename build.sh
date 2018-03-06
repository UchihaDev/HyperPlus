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
VERSION="JamMonster"
DATE=$(date +"%d-%m-%Y-%I-%M")
DEVICE="VKY"
FINAL_ZIP=$KERNEL_NAME-$VERSION-$DATE-$DEVICE.zip

# Dirs
KERNEL_DIR=~/Desktop/Code_Opensource
OUT_DIR=~/Desktop/out
UPLOAD_DIR=~/Desktop/Files/flash_zip
ANYKERNEL_DIR=$KERNEL_DIR/AnyKernel2
KERNEL_IMG=~/Desktop/out/arch/arm64/boot/Image
DT_IMAGE=$OUT_DIR/arch/arm64/boot/dt.img
DTBTOOL=~/Desktop/tools/tools/dtbToolCM

# Delete this annoying files
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

# Make DT.IMG
function make_dt(){
$DTBTOOL -2 -o $DT_IMAGE -s 2048 -p $KERNEL_DIR/scripts/dtc/ $KERNEL_DIR/arch/arm/boot/dts/
}

# Making zip
function make_zip() {
cp $KERNEL_IMG $ANYKERNEL_DIR
cp $DT_IMAGE $ANYKERNEL_DIR
mkdir -p $UPLOAD_DIR
cd $ANYKERNEL_DIR
zip -r9 UPDATE-AnyKernel2.zip * -x README UPDATE-AnyKernel2.zip
mv $ANYKERNEL_DIR/UPDATE-AnyKernel2.zip $UPLOAD_DIR/$FINAL_ZIP
}

# Options
function options() {
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
     make_kernel 
     make_dt ;;
  2) echo -e "$cyan***********************************************"
     echo -e "          	Clean          "
     echo -e "***********************************************$nocol"
     make ARCH=arm64 distclean
     rm -rf ../out
     make_kernel
     make_dt ;;
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
rm -rf $ANYKERNEL_DIR/Image
rm -rf $ANYKERNEL_DIR/dt.img
rm -rf $ANYKERNEL_DIR/modules/*.ko
rm -rf $KERNEL_DIR/arch/arm/boot/dts/*.dtb
rm -rf $DT_IMAGE
}

options
cleanup
BUILD_END=$(date +"%s")
DIFF=$(($BUILD_END - $BUILD_START))
echo -e "$yellow Build completed in $(($DIFF / 60)) minute(s) and $(($DIFF % 60)) seconds.$nocol"


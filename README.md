# mercury
Mercury is a simple OS kernel written in C from scratch

# MISC

```
sudo apt update && sudo apt install -y clang llvm lld qemu-system-riscv32 curl

# Also, download OpenSBI (think of it as BIOS/UEFI for PCs):
# When you run QEMU, make sure opensbi-riscv32-generic-fw_dynamic.bin is in your current directory. If it's not, you'll see error
curl -LO https://github.com/qemu/qemu/raw/v8.0.4/pc-bios/opensbi-riscv32-generic-fw_dynamic.bin
```

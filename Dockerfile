# should build based on image https://github.com/rickliujh/dotfiles/blob/main/dockerfiles/Dockerfile.base
FROM devbase:v0.1

RUN apt update && apt install -y clang llvm lld qemu-system-riscv32 curl

# Busybox -- 8b996feb

## Binary Identity

| Property | Value |
|----------|-------|
| Software | Busybox |
| Version | v1.19.4 (2012-02-04) |
| Architecture | ARM 32-bit ELF |
| ABI | EABI5 |
| Linking | Dynamically linked |
| Debug info | not present (stripped) |
| MD5 hash (first 8) | 8b996feb |

## Obtaining the Binary

The binary is not included in this repository. It can be downloaded from the
[iot-binary-dataset](https://github.com/Aarno-Labs/iot-binary-dataset/tree/main/executables/8/b/996/feb)
repository. Once obtained, place it at `shareddata/busybox` relative to this directory.

Run the following command from the directory containing this README:
```sh
curl -L -o shareddata/busybox \
  https://github.com/Aarno-Labs/iot-binary-dataset/raw/main/executables/8/b/996/feb/8b996feb
```

## Header Files

Header files are provided at two levels:

**Shared headers** (`shareddata/header.c`, `shareddata/header_*.h`): type
definitions and declarations derived from the Busybox v1.19.4 source code,
shared across all lifting tests. The shared header is self-contained, that
is, all system #includes have been removed. Referenced type definitions
have been included explicitly.

**Per-test header** (`liftings/<dir>/fileheader.c`): includes the shared
`header.c` and adds declarations specific to the source file under test —
static and global variable definitions and function signatures.
Macros are expanded and `#ifdef` guards are resolved according to the `-D`
flags in effect for that source file, so data structure definitions reflect
the actual layout encountered in the binary.

## Userdata

Userdata hints are provided at two levels:

**Shared userdata** (`shareddata/userdata.json`): function names and symbolic
addresses that apply across the entire binary.

**Per-test userdata** (`liftings/<dir>/file_userdata.json`): function-specific
annotations that provide addresses for static variables in that file.

Both levels are passed to the analyzer via the `--hints` option.

## Liftings

The `liftings/` directory contains 9 test cases. Each subdirectory corresponds
to a source file from the Busybox source tree, using `__` as a path separator.
All source files originate from under the `crypto/` subtree.

| Directory | Source file |
|-----------|-------------|
| `libbb__bb_pwd` | `libbb/bb_pwd.c` |
| `libbb__bb_strtonum` | `libbb/bb_strtonum.c` |
| `libbb__copyfd` | `libbb/copyfd.c` |
| `libbb__procps` | `libbb/procps.c` |
| `libbb__xfuncs` | `libbb/xfuncs.c` |
| `libbb__xfuncs_printf` | `libbb/xfuncs_printf.c` |
| `miscutils__less` | `miscutils/less.c` |
| `networking__udhcp__common` | `networking/udhcp/common.c` |
| `networking__udhcp__domain_codec` | `networking/udhcp/domain_codec.c` |


Each lifting directory contains:

| File | Description |
|------|-------------|
| `vars.sh` | Defines the functions to be lifted and the path to the binary |
| `fileheader.c` | Per-test header: includes shared headers and adds source-file-specific declarations |
| `file_userdata.json` | Per-test userdata: function annotations naming registers and stack locations to match the source code |
| `test.00.ch-analyze.sh` | Analyze the selected functions |
| `test.01.ch-produce-pir.sh` | Produce PIR (decompiled output) |


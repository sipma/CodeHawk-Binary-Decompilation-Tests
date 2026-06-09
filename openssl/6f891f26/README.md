# OpenSSL libcrypto — 6f891f26

## Binary Identity

| Property | Value |
|----------|-------|
| Software | OpenSSL libcrypto |
| Version | 1.0.1g (7 Apr 2014) |
| Architecture | ARM 32-bit ELF |
| ABI | EABI4 |
| Linking | Dynamically linked |
| Debug info | Present (not stripped) |
| MD5 hash (first 8) | 6f891f26 |

## Obtaining the Binary

The binary is not included in this repository. It can be downloaded from the
[iot-binary-dataset](https://github.com/Aarno-Labs/iot-binary-dataset/tree/main/executables/6/f/891/f26)
repository. Once obtained, place it at `shareddata/6f891f26` relative to this directory.

Run the following command from the directory containing this README:
```sh
curl -L -o shareddata/6f891f26 \
  https://github.com/Aarno-Labs/iot-binary-dataset/raw/main/executables/6/f/891/f26/6f891f26
```

## Header Files

Header files are provided at two levels:

**Shared headers** (`shareddata/header.c`, `shareddata/header_*.h`): type
definitions and declarations derived from the OpenSSL 1.0.1g source code,
shared across all lifting tests.

**Per-test header** (`liftings/<dir>/fileheader.c`): includes the shared
`header.c` and adds declarations specific to the source file under test —
static and global variable definitions and function signatures, each annotated
with their source location (`chkc_srcloc`) and binary address (`chkx_binloc`).
Macros are expanded and `#ifdef` guards are resolved according to the `-D`
flags in effect for that source file, so data structure definitions reflect
the actual layout encountered in the binary.

## Userdata

Userdata hints are provided at two levels:

**Shared userdata** (`shareddata/userdata.json`): function names and symbolic
addresses that apply across the entire binary.

**Per-test userdata** (`liftings/<dir>/userdata.json`): function-specific
annotations that provide names for registers and stack locations to match
the original source code, making it easier to compare the lifting output
against the source. The structure of these annotations is described in the
[function annotations user guide](https://github.com/static-analysis-engineering/CodeHawk-Binary/blob/master/doc/user-guide/userdata/function-annotations.md).

Both levels are passed to the analyzer via the `--hints` option.

## Liftings

The `liftings/` directory contains 20 test cases. Each subdirectory corresponds
to a source file from the OpenSSL source tree, using `__` as a path separator.
All source files originate from under the `crypto/` subtree.

| Directory | Source file |
|-----------|-------------|
| `crypto__asn1__a_bitstr` | `crypto/asn1/a_bitstr.c` |
| `crypto__asn1__a_d2i_fp` | `crypto/asn1/a_d2i_fp.c` |
| `crypto__asn1__a_enum` | `crypto/asn1/a_enum.c` |
| `crypto__asn1__a_gentm` | `crypto/asn1/a_gentm.c` |
| `crypto__asn1__a_mbstr` | `crypto/asn1/a_mbstr.c` |
| `crypto__asn1__ameth_lib` | `crypto/asn1/ameth_lib.c` |
| `crypto__asn1__x_name` | `crypto/asn1/x_name.c` |
| `crypto__evp__bio_b64` | `crypto/evp/bio_b64.c` |
| `crypto__evp__bio_enc` | `crypto/evp/bio_enc.c` |
| `crypto__evp__evp_lib` | `crypto/evp/evp_lib.c` |
| `crypto__evp__names` | `crypto/evp/names.c` |
| `crypto__evp__p_lib` | `crypto/evp/p_lib.c` |
| `crypto__evp__pmeth_lib` | `crypto/evp/pmeth_lib.c` |
| `crypto__rand__rand_lib` | `crypto/rand/rand_lib.c` |
| `crypto__ui__ui_lib` | `crypto/ui/ui_lib.c` |
| `crypto__x509v3__v3_purp` | `crypto/x509v3/v3_purp.c` |
| `crypto__x509__x509_cmp` | `crypto/x509/x509_cmp.c` |
| `crypto__x509__x509_def` | `crypto/x509/x509_def.c` |
| `crypto__x509__x509_vfy` | `crypto/x509/x509_vfy.c` |
| `crypto__x509__x509_vpm` | `crypto/x509/x509_vpm.c` |

Each lifting directory contains:

| File | Description |
|------|-------------|
| `vars.sh` | Defines the functions to be lifted and the path to the binary |
| `fileheader.c` | Per-test header: includes shared headers and adds source-file-specific declarations |
| `userdata.json` | Per-test userdata: function annotations naming registers and stack locations to match the source code |
| `expected_liftings.txt` | Ground-truth decompiled output for the selected functions |
| `test.00.ch-analyze.notime.pass.sh` | Analyze the selected functions |
| `test.01.ch-produce-pir.notime.pass.sh` | Produce PIR (decompiled output) |
| `test.02.ch-check-liftings.notime.pass.sh` | Compare output against expected liftings |

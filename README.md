# CodeHawk-Binary-Decompilation-Tests

Test cases for decompilation of IoT binaries of open-source code by the
[CodeHawk Binary Analyzer](https://github.com/static-analysis-engineering/CodeHawk-Binary).

## Repository Structure

The repository is organized by software package and binary, with the binary
identified by the first 8 characters of its MD5 hash:

```
<package>/
  <hash>/
    README.md       - binary identity and provenance
    shareddata/     - header files and shared userdata derived from the source code
    liftings/       - decompilation test cases, one directory per source file
```

Currently available:

| Package | Binary MD5 prefix | Description |
|---------|------|-------------|
| `busybox` | `8b996feb` | Busybox v1.19.4, ARM 32-bit ELF |
| `openssl` | `6f891f26` | OpenSSL 1.0.1g libcrypto, ARM 32-bit ELF |

The number of functions analyzed and lifted per binary is shown in [STATUS](STATUS.md).

## Prerequisites

Running the tests requires the CodeHawk Binary Analyzer (`chkx`). Installation
instructions are provided in the following repositories:

- [CodeHawk Binary Analyzer](https://github.com/static-analysis-engineering/CodeHawk-Binary)
- [CodeHawk OCaml Analyzer](https://github.com/static-analysis-engineering/codehawk/tree/master/CodeHawk) (required by the above)

## Obtaining Binaries

The test binaries are not included in this repository. They can be obtained from
[iot-binary-dataset](https://github.com/Aarno-Labs/iot-binary-dataset), a
repository of IoT binaries of open-source code, organized by the same hash
used here. See the `README.md` in each binary's directory for the exact
location and setup instructions.

## Running Tests

Each directory under `liftings/` corresponds to a source file and contains
numbered test scripts to be run in sequence from within that directory.
The scripts must be run in order, as each depends on the output of the previous:

| Script | Description |
|--------|-------------|
| `test.00.ch-analyze.notime.pass.sh` | Analyze the selected functions in the binary |
| `test.01.ch-produce-pir.notime.pass.sh` | Produce PIR (decompiled output) for the functions |
| `test.02.ch-check-liftings.notime.pass.sh` | Compare the output against the expected liftings |
| `test.10.check-errors.sh` | Lift the functions in `FNS_PENDING_ERRORS`, recording errors in `logs/error_log.json` |


## Results

A more detailed breakdown of the current results and limitations are shown in the overview pages
- [STATUS](STATUS.md), and
- [ERRORS](ERRORS.md)

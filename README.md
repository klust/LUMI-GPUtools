# LUMI-GPU-tools

A repostiroy of tools to ease work with the AMD GPUs on LUMI.

## Structure of the repository

* src: The source files for the actual tools.
* scripts: Optional script versions of some of the tools.
* man: Man pages for the tools.
* experiments: Various programs used to test out the APIs that are used in the
  scripts. May be removed in a later iterations as they are not essential at all
  here and only here for convenience.

## Build instructions

To build the tools, use the Makefile in the root directory. It supports the following
targets:

* build: Build the binaries in the bin subdirectory.
* test: Run some tests on the generated binaries.
* install: Install in the directory given by PREFIX=<dir> on the Make command line.
  The default for quick testing is the INSTALL subdirectory in the root of this project.
* clean: Clean all binaries and intermediate files.

The following environment variables are supported:

* CC: The C compiler to be used.
* CFLAGS: The flags to be passed to the C compiler when building.

In principle it is possible to re-run the tests after the installation using the installed
binaries as an additional check. In this case the target `test` of the root Makefile should
be executed setting `BUILDBINDIR` on the command line to the full path of the binary directory.
A relative path will be misleading as the tests are executed in the context of the `src` 
directory so any relative path should be relative with respect to that directory.

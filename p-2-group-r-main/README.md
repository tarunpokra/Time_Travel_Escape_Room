# Template for CPSC2720 Major Project: Text-based Adventure Game


Last Updated: 2022-12-15 by Nicole Wilson &lt;n.wilson@uleth.ca&gt;

Notes:

* The Makefile and .gitlab-ci.yml files are set up to run on Ubuntu.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++
  * Style Check: cpplint
  * Static Check: cppcheck
  * Coverage Check: gcov/lcov
  * Memory Check: valgrind
  * Unit Test: gtest 
  * Documentation: doxygen
* See the version report on the pipeline.

Certain assumptions have been made:
* One repo contains the files for one project.
* All unit testing files are found in <code>test/</code> including <code>main.cpp</code>.
* All header files for the project are found in <code>include/</code> and named <code>*.h</code>, every class must have a header file.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.

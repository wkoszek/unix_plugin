# UNIX plugin infrastructure

This program was meant to be used as an example on how
plugin infrastructure works. Imagine you have a program
such as a music player which comes as a main "infrastructure".
Program's architecture is such that if it sees `mp3` file,
it'll load an `MP3` plugin, if `ogg` file, then it'll load
load an `OGG` plugin.

The advantage of this is that the architecture of the program
is clean and generalized.

# How to build

To build, do:

	make

# How to test?

	make test

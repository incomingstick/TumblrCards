# TumblrCards - Open Source

```
     /:\                       (""")
     |:|          /$$           III            TumblrCards:
     |:|         | $$         __III__             A text based multiplayer
     |:|        /$$$$$$     /:-.___,-:\           strategy card game.
     |:|       |_  $$_/     \]  |:|  [/
     |:|         | $$           |:|               Written by members of the
 /]  |:|  [\     | $$ /$$       |:|               Tumblr Computer Science community.
 \:-'"""`-:/     | "$$$$/       |:|
   ""III""        \___/         |:|
     III                        |:|
    (___)                       \:/
```

TumblrCards (we are working on the name) is a text based multiplayer strategy card game written by members of the Tumblr Computer Science community.

The [`TumblrCards`](https://github.com/TumblrCommunity/TumblrCards) repository is where we do development and there are many ways you can participate in the project, for example:

* [Submit bugs and feature requests](https://github.com/TumblrCommunity/TumblrCards/issues) and help us verify as they are checked in
* Review [source code changes](https://github.com/TumblrCommunity/TumblrCards/pulls)
* Review the [wiki](https://github.com/TumblrCommunity/TumblrCards/wiki) and make changes for anything from typos to new content
* Review the [contributing](.github/CONTRIBUTING.md) page for a list of guidelines and tasks


## Feedback

* Ask a question on [GitHub Issues](https://github.com/TumblrCommunity/TumblrCards/issues) with the question tag.
* Request a feature on [GitHub Issues](https://github.com/TumblrCommunity/TumblrCards/issues) with the enhancement tag.
* File a bug in [GitHub Issues](https://github.com/TumblrCommunity/TumblrCards/issues) with the bug tag.
* Message import-os [(incomingstick)](https://github.com/incomingstick) on [Tumblr](https://import-os.tumblr.com/ask) with questions or other feedback.

### Team Communication

This project will be using an invite only [Discord](https://www.discordapp.com) channel. If you would like an invite, you can message import-os [(incomingstick)](https://github.com/incomingstick) on [Tumblr](https://import-os.tumblr.com/ask).

## Building

CMake is used to build the project. If you're using an IDE, it may be able to detect the source tree and build settings automatically. No outside libraries are currently used, so most (if not all) systems should be good to go.

To build, make sure you have the following:
* [CMake](https://cmake.org/) 3.0 or greater

### Building on *NIX systems

1. Make a new directory called "build" in the project root. 
2. Move into that directory and run `cmake ..`. This will generate a makefile.
3. Run `make`. Optionally, if you have extra CPU cycles to spare, you can use `make -jX`, where X is the number of CPUs you have.
4. If everything built successfully, you can run it by typing `./tumblrcards` in your terminal.

### Building on Windows systems

Coming soon. For now build using [Cygwin](https://www.cygwin.com/), [MinGW](http://www.mingw.org/), [Windows Subsystem for Linux](https://msdn.microsoft.com/en-us/commandline/wsl/about), or the like and follow the "Building on *NIX systems" instructions above.

## License
[Eclipse Public License - v 1.0](LICENSE)

# TTY::Screen

> Terminal screen size detection for Linux, MacOS, or Windows.

This is a port of Piotr Murach's [TTY::Screen](https://github.com/piotrmurach/tty-screen) from ruby to mruby.

## Prerequisites:

gcc or clang, bison, and ruby.

By default, the `build_config.rb` will attempt to use clang unless you are on windows.

## Try it out

1. `rake compile` to compile mruby with **TTY:Screen** modules included
2. `mruby/bin/mirb` to start the mruby interactive shell
3. Try the commands in the usage section

## Usage

**TTY::Screen** allows you to detect terminal screen size by calling the `size` method which returns a [height, width] tuple.

```ruby
TTY::Screen.size     # => [51, 280]
```

Terminal width:

```ruby
TTY::Screen.width    # => 280
TTY::Screen.columns  # => 280
TTY::Screen.cols     # => 280
```

Terminal height:

```ruby
TTY::Screen.height   # => 51
TTY::Screen.rows     # => 51
TTY::Screen.lines    # => 51
```

## Add to your mruby project

Add this line to your application's mrbgem.rake file:
```ruby
spec.add_dependency 'mruby-tty-screen', github: 'jeremyjung/mruby-tty-screen'
```

## Developing on Windows

Windows does not include any of the mruby dependencies (ruby, gcc, bison) so they'll need to be installed.

1.  Install [rubyinstaller 2.4.3-2 \(x64\)](https://rubyinstaller.org/downloads/)
2.  When the MSYS2 command prompt appears, hit enter to install default toolchain
3.  After installation is complete, open a terminal and go to the mruby-tty-screen directory
4.  Run `ridk enable`
5.  Run `pacman -S bison`
6.  Run `rake compile`

Note that any time you open a terminal, you must run `ridk enable` before attempting to run `rake compile` in Windows or the compilation will fail.

## Why weren't tests ported?

mruby has no stubbing library that would allow the porting of existing tests.

## What was changed?

All private class methods were changed to public as mruby does not support them.

All references to jruby were removed.

Keyword arguments are unsupported in mruby so they were changed to a hash parameter.

All require statements were removed as mruby is compiled.

Fiddle code was changed to native C as mruby does not include fiddle.

Removed references to SystemCallError which do not exist in the mruby-process gem.

Remove dependencies on mruby-io-console (sys/wait.h does not exist) and mruby-process (sys/ioctl.h does not exist) on windows.

## Contributing

1. Fork it ( https://github.com/jeremyjung/mruby-tty-screen/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Copyright

Copyright (c) 2014-2018 Piotr Murach. See LICENSE for further details.

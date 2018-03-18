# TTY::Screen

> Terminal screen size detection for Linux and MacOS.

This is a port of Piotr Murach's [TTY::Screen](https://github.com/piotrmurach/tty-screen) from ruby to mruby.

## Try it out

#### Prerequisites:

MacOS or Linux, clang, and ruby.
1. `rake compile` to compile mruby
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

## Windows support

Windows is not yet supported.  The original codebase makes use of fiddle to communicate with the Windows native API.  This will need to be written in C as mruby does not include fiddle.

## Why weren't tests ported?

mruby has no stubbing library that would allow the porting of existing tests.

## What was changed?

All private class methods are changed to public as mruby does not support them.

All references to jruby were removed as they do not apply to mruby

Keyword arguments are unsupported in mruby so they were changed to a hash parameter.

All require statements were removed as mruby is compiled.

## Contributing

1. Fork it ( https://github.com/jeremyjung/mruby-tty-screen/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Copyright

Copyright (c) 2014-2018 Piotr Murach. See LICENSE for further details.

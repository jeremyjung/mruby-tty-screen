#include <mruby.h>
#include <mruby/array.h>
#include <mruby/value.h>

#ifdef _WIN32
  #include <windows.h>
  #include <stdio.h>
  #include <conio.h>

  HANDLE stdoutHandle;
#endif

static mrb_value mrb_size_from_win_api(mrb_state* mrb, mrb_value self) {
  #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO cBuffer;
    SMALL_RECT wSize;

    if (!GetConsoleScreenBufferInfo(stdoutHandle, &cBuffer)) {
      return mrb_nil_value();
    }

    wSize = cBuffer.srWindow;
    return mrb_ary_new_from_values(mrb, 2, [mrb_fixnum_value((mrb_int)(wSize.Bottom - wSize.Top + 1)),
                                            mrb_fixnum_value((mrb_int)(wSize.Right - wSize.Left + 1))]);
  #else
    return mrb_nil_value();
  #endif
}

void mrb_mruby_tty_screen_gem_init(mrb_state* mrb) {
  struct RClass *tty, *screen;

  tty = mrb_define_module(mrb, "TTY");
  screen = mrb_define_module_under(mrb, tty, "Screen");
  mrb_define_class_method(mrb, screen, "size_from_win_api", mrb_size_from_win_api, MRB_ARGS_NONE());
}

void mrb_mruby_tty_screen_gem_final(mrb_state* mrb) {

}

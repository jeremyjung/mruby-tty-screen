#include <mruby.h>
#include <mruby/array.h>
#include <mruby/value.h>

#ifdef _WIN32
  #include <windows.h>
  #include <stdio.h>
  #include <conio.h>
#endif

static mrb_value mrb_size_from_win_api(mrb_state* mrb, mrb_value self) {
  #ifdef _WIN32
    HANDLE stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO c_buffer;
    SMALL_RECT w_size;

    if (!GetConsoleScreenBufferInfo(stdoutHandle, &c_buffer)) {
      return mrb_nil_value();
    }

    w_size = c_buffer.srWindow;
    mrb_value terminal_size[2];
    terminal_size[0] = mrb_fixnum_value((mrb_int)(w_size.Bottom - w_size.Top + 1));
    terminal_size[1] = mrb_fixnum_value((mrb_int)(w_size.Right - w_size.Left + 1));
    return mrb_ary_new_from_values(mrb, 2, terminal_size);
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

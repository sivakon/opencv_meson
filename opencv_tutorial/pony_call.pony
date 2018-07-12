"""
FFI that sends a string to C that blurs the image from the filepath
"""
use "path:./builddir/"
use "lib:imagelib"

actor Main
  new create(env: Env) =>
    env.out.print("Hello, FFI!")
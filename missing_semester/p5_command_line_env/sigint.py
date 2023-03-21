#!/usr/bin/env python
import signal, time

def handler(signum, frame):
    print("\n I get a sigint, but I am not stopping")

signal.signal(signal.SIGINT, handler)

i = 0
while True:
  time.sleep(1)
  print(i)
  i += 1
#!/bin/bash
cat retroradio_23-04-24_1721.iq |
  tcc -lm -run fmdemod.c |
  sox -t raw -r 300000 -e unsigned -b 8 -c 1 - -t raw - rate 48000 sinc -15k |
  aplay -f U8 -c1 -r 48000 --buffer-size=200000

#!/bin/bash
nc teto.sch.bme.hu 7373 | tcc -lm -run fmdemod.c | sox -t raw -r 240000 -e unsigned -b 8 -c 1 - -t raw - rate 48000 | aplay -f U8 -c1 -r 48000 --buffer-size=200000

#!/bin/sh
# Ferihegy információ 127.4-en, -50 kHz
rtl_sdr -f 127350000 -s 300000 -g 35 - | ncat -4l 7373 -k --send-only
